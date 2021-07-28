<?php

$key = "The Shared Key"
$message = "The message to be hashed"

// to lowercase hexits
hash_hmac('sha256', $message, $key);

// to base64
base64_encode(hash_hmac('sha256', $message, $key, true));