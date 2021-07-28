package main

import (
	"crypto/hmac"
	"crypto/sha256"
	"encoding/base64"
	"encoding/hex"
)

func main() {
	secret := []byte("the shared secret key here")
	message := []byte("the message to hash here")
	
	hash := hmac.New(sha256.New, secret)
	hash.Write(message)
	
	// to lowercase hexits
	hex.EncodeToString(hash.Sum(nil))
	
	// to base64
	base64.StdEncoding.EncodeToString(hash.Sum(nil))
}
