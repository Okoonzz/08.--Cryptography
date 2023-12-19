package main

import (
	"encoding/binary"
	"encoding/hex"
	"flag"
	"fmt"
	"strconv"
)

// Magic number sha256
var cons = []uint32{
	0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1,
	0x923f82a4, 0xab1c5ed5, 0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
	0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174, 0xe49b69c1, 0xefbe4786,
	0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
	0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147,
	0x06ca6351, 0x14292967, 0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
	0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85, 0xa2bfe8a1, 0xa81a664b,
	0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
	0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a,
	0x5b9cca4f, 0x682e6ff3, 0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
	0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2,
}

func rightRotate(value uint32, bits uint32) uint32 {
	return (value>>bits | value<<(32-bits)) & 0xFFFFFFFF
}

func add32(args ...uint32) uint32 {
	var sum uint32
	for _, arg := range args {
		sum += arg
	}
	return sum
}

func PaddingMess(msg []byte, secretMsgLen int) []byte {
	lenOrig := 8 * (secretMsgLen + len(msg))
	msg = append(msg, 0x80)

	for (len(msg)+secretMsgLen+8)%64 != 0 {
		msg = append(msg, 0x00)
	}

	// Add original message length to end as an 8-byte big-endian integer
	lenBytes := make([]byte, 8)
	binary.BigEndian.PutUint64(lenBytes, uint64(lenOrig))
	msg = append(msg, lenBytes...)

	return msg
}

func sha256LengthExtension(dataStr string, prevHash string, secretMsgLen int, prevMessage string) (string, []byte) {
	msg := []byte(dataStr)
	prevMessageBytes := []byte(prevMessage)

	prevMessageWithPadding := PaddingMess(prevMessageBytes, secretMsgLen)
	dataPadded := PaddingMess(msg, secretMsgLen+len(prevMessageWithPadding))

	tmphash0, _ := strconv.ParseUint(prevHash[0:8], 16, 32)
	tmphash1, _ := strconv.ParseUint(prevHash[8:16], 16, 32)
	tmphash2, _ := strconv.ParseUint(prevHash[16:24], 16, 32)
	tmphash3, _ := strconv.ParseUint(prevHash[24:32], 16, 32)
	tmphash4, _ := strconv.ParseUint(prevHash[32:40], 16, 32)
	tmphash5, _ := strconv.ParseUint(prevHash[40:48], 16, 32)
	tmphash6, _ := strconv.ParseUint(prevHash[48:56], 16, 32)
	tmphash7, _ := strconv.ParseUint(prevHash[56:64], 16, 32)

	for i := 0; i < len(dataPadded); i += 64 {
		dataChunk := dataPadded[i : i+64]

		// Message schedule array
		w := make([]uint32, 64)

		// Chunk forms the start of the message schedule array
		for i := 0; i < 16; i++ {
			w[i] = binary.BigEndian.Uint32(dataChunk[(4 * i):(4*i + 4)])
		}

		// Extend to form the rest of the message schedule array
		for i := 16; i < 64; i++ {
			s0 := rightRotate(w[i-15], 7) ^ rightRotate(w[i-15], 18) ^ (w[i-15] >> 3)
			s1 := rightRotate(w[i-2], 17) ^ rightRotate(w[i-2], 19) ^ (w[i-2] >> 10)
			w[i] = add32(w[i-16], s0, w[i-7], s1)
		}

		c1 := tmphash0
		c2 := tmphash1
		c3 := tmphash2
		c4 := tmphash3
		c5 := tmphash4
		c6 := tmphash5
		c7 := tmphash6
		c8 := tmphash7

		// The compression function
		for i := 0; i < 64; i++ {
			S1 := rightRotate(uint32(c5), 6) ^ rightRotate(uint32(c5), 11) ^ rightRotate(uint32(c5), 25)
			ch := (c5 & c6) ^ (^c5 & c7)
			tmp1 := add32(uint32(c8), S1, uint32(ch), cons[i], w[i])
			S0 := rightRotate(uint32(c1), 2) ^ rightRotate(uint32(c1), 13) ^ rightRotate(uint32(c1), 22)
			maj := (c1 & c2) ^ (c1 & c3) ^ (c2 & c3)
			tmp2 := add32(S0, uint32(maj))

			c8 = c7
			c7 = c6
			c6 = c5
			c5 = uint64(add32(uint32(c4), tmp1))
			c4 = c3
			c3 = c2
			c2 = c1
			c1 = uint64(add32(tmp1, tmp2))
		}

		tmphash0 = uint64(add32(uint32(tmphash0), uint32(c1)))
		tmphash1 = uint64(add32(uint32(tmphash1), uint32(c2)))
		tmphash2 = uint64(add32(uint32(tmphash2), uint32(c3)))
		tmphash3 = uint64(add32(uint32(tmphash3), uint32(c4)))
		tmphash4 = uint64(add32(uint32(tmphash4), uint32(c5)))
		tmphash5 = uint64(add32(uint32(tmphash5), uint32(c6)))
		tmphash6 = uint64(add32(uint32(tmphash6), uint32(c7)))
		tmphash7 = uint64(add32(uint32(tmphash7), uint32(c8)))
	}

	// Create bytearray contain string hash
	hash := make([]byte, 32)
	binary.BigEndian.PutUint32(hash[0:4], uint32(tmphash0))
	binary.BigEndian.PutUint32(hash[4:8], uint32(tmphash1))
	binary.BigEndian.PutUint32(hash[8:12], uint32(tmphash2))
	binary.BigEndian.PutUint32(hash[12:16], uint32(tmphash3))
	binary.BigEndian.PutUint32(hash[16:20], uint32(tmphash4))
	binary.BigEndian.PutUint32(hash[20:24], uint32(tmphash5))
	binary.BigEndian.PutUint32(hash[24:28], uint32(tmphash6))
	binary.BigEndian.PutUint32(hash[28:32], uint32(tmphash7))

	// convert bytearray to hex
	hashStr := hex.EncodeToString(hash)

	// Return string hash and mess padding
	return hashStr, append(prevMessageWithPadding, msg...)
}
func main() {
	hash := flag.String("s", "", "Hash (secret || message)")
	message := flag.String("m", "", "Message")
	append := flag.String("a", "", "Malicious (secret || message || malicious)")
	keyLength := flag.Int("k", 0, "Length of secret key")

	flag.Parse()

	if flag.NFlag() < 4 {
		fmt.Println("Wrong format!!!")
		fmt.Println("<-s sig> <-m message> <-a malicious> <-k lenKey>")
		return
	}
	newHash, newMessage := sha256LengthExtension(*append, *hash, *keyLength, *message)

	fmt.Println("[*] New SHA256: ", newHash)
	fmt.Printf("[*] New message: %#v\n", newMessage)
	fmt.Printf("[*] New message (hex): %x\n", newMessage)
}
