var request = require('request');

var speed = parseInt(process.argv[2]);
require('./commands').climb(speed);
