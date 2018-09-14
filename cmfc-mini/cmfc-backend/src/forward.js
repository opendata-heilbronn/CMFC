var request = require('request');

request('http://192.168.178.22/?s1=170', function (error, response, body) { });
request('http://192.168.178.22/?s2=170', function (error, response, body) { });
request('http://192.168.178.22/?s3=10', function (error, response, body) { });
request('http://192.168.178.22/?s4=10', function (error, response, body) { });
