extern crate hmac;
extern crate sha2;
extern crate base64;
extern crate hex;

use sha2::Sha256;
use hmac::{Hmac, Mac};

fn main() {
    type HmacSha256 = Hmac<Sha256>;

    let secret = "the shared secret key here";
    let message = "the message to hash here";

    let mut mac = HmacSha256::new_varkey(secret.as_bytes()).unwrap();

    mac.input(message.as_bytes());

    let hash_message = mac.result().code();

    // to lowercase hexits
    hex::encode(&hash_message);

    // to base64
    base64::encode(&hash_message);
}