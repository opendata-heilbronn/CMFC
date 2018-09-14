var request = require('request');

module.exports = {

    turn: function(speed) {
        var s1 = 90 - speed;

        request('http://192.168.178.104/?s1=' + s1, function (error, response, body) { });
        request('http://192.168.178.104/?s2=' + s1, function (error, response, body) { });
        request('http://192.168.178.104/?s3=' + s1, function (error, response, body) { });
        request('http://192.168.178.104/?s4=' + s1, function (error, response, body) { });
    },

    move: function(speed) {
        var s1 = 90 - speed;
        var s2 = 90 + speed;

        request('http://192.168.178.104/?s1=' + s1, function (error, response, body) { });
        request('http://192.168.178.104/?s2=' + s1, function (error, response, body) { });
        request('http://192.168.178.104/?s3=' + s2, function (error, response, body) { });
        request('http://192.168.178.104/?s4=' + s2, function (error, response, body) { });

    },

    stop: function() {
        request('http://192.168.178.104/?s1=90', function (error, response, body) { });
        request('http://192.168.178.104/?s2=91', function (error, response, body) { });
        request('http://192.168.178.104/?s3=90', function (error, response, body) { });
        request('http://192.168.178.104/?s4=93', function (error, response, body) { });
    },

    climb: function(speed) {
        var front = 90 - speed;
        var back = 90 + (speed / 2);

        request('http://192.168.178.104/?s1=' + back, function (error, response, body) { });
        request('http://192.168.178.104/?s2=90' + front, function (error, response, body) { });
        request('http://192.168.178.104/?s3=90' + back, function (error, response, body) { });
        request('http://192.168.178.104/?s4=90' + front, function (error, response, body) { });
    }
}