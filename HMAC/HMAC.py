import hashlib
import hmac
import base64

message = bytes('the message to hash here', 'utf-8')
secret = bytes('the shared secret key here', 'utf-8')

hash = hmac.new(secret, message, hashlib.sha256)

# to lowercase hexits
hash.hexdigest()

# to base64
base64.b64encode(hash.digest())
