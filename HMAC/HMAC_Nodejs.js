var crypto = require('crypto');

var key = "The shared secret Key";
var message = "The Message to be hashed";

var hash = crypto.createHmac('sha256', key).update(message);

// to lowercase hexits
hash.digest('hex');

// to base64
hash.digest('base64');