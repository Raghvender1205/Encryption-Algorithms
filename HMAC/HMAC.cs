using System;
using System.Security.Cryptography;
using System.Text;

class MainClass {
    public static void Main (string[] args) {
        string key = "the shared secret key here";
        string message = "the message to hash here";
        
        byte[] keyByte = new ASCIIEncoding().GetBytes(key);
        byte[] messageBytes = new ASCIIEncoding().GetBytes(message);
        
        byte[] hashmessage = new HMACSHA256(keyByte).ComputeHash(messageBytes);
        
        // to lowercase hexits
        String.Concat(Array.ConvertAll(hashmessage, x => x.ToString("x2")));
        
        // to base64
        Convert.ToBase64String(hashmessage);
    }
}
