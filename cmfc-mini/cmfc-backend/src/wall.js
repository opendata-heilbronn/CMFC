var request = require('request');

var speed = parseInt(process.argv[2]);

request('http://192.168.12.206/?wall=' + speed, function (error, response, body) { });
