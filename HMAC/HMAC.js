// Using the Web Crypto API
const key = "The shared secret key";
const message = "The message to be hashed";

const getUtf8Bytes = str => 
    new Uint8Array(
        [...unescape(encodeURIComponent(str))].map(c => c.charCodeAt(0))
    );

const keyBytes = getUtf8Bytes(key);
const messageBytes = getUtf8Bytes(message);

const cryptoKey = await crypto.subtle.importKey(
    'raw', keyBytes, { name: 'HMAC', hash: 'SHA-256' },
    true, ['sign']
);
const sig = await crypto.subtle.sign('HMAC', cryptoKey, messageBytes);

// to lowercase hexits
[...new Uint8Array(sig)].map(b => b.toString(16).padStart(2, '0')).join('');

// to base64
btoa(String.fromCharCode(...new Uint8Array(sig)));