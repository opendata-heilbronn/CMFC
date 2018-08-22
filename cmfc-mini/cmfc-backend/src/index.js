
var keypress = require('keypress');
var request = require('request');

var ip = "192.168.178.13";
var stepSize = 5;

var servosSpeed = [90, 90, 90, 90];

keypress(process.stdin);

function sendSpeeds() {
    request('http://' + ip + '/?s1=' + servosSpeed[0], function (error, response, body) { });
    request('http://' + ip + '/?s2=' + servosSpeed[1], function (error, response, body) { });
    request('http://' + ip + '/?s3=' + servosSpeed[2], function (error, response, body) { });
    request('http://' + ip + '/?s4=' + servosSpeed[3], function (error, response, body) { });
}

process.stdin.on('keypress', function (ch, key) {
    if (key && key.ctrl && key.name == 'c') {
        process.stdin.pause();
    }

    if (key && key.name == 'up') {
        servosSpeed[0] += stepSize;
        servosSpeed[1] += stepSize;
        servosSpeed[2] -= stepSize;
        servosSpeed[3] -= stepSize;

        sendSpeeds();
    }

    if (key && key.name == 'down') {
        servosSpeed[0] -= stepSize;
        servosSpeed[1] -= stepSize;
        servosSpeed[2] += stepSize;
        servosSpeed[3] += stepSize;

        sendSpeeds();
    }

    if (key && key.name == 'left') {
        servosSpeed[0] -= stepSize;
        servosSpeed[1] -= stepSize;
        servosSpeed[2] -= stepSize;
        servosSpeed[3] -= stepSize;

        sendSpeeds();
    }

    if (key && key.name == 'right') {
        servosSpeed[0] += stepSize;
        servosSpeed[1] += stepSize;
        servosSpeed[2] += stepSize;
        servosSpeed[3] += stepSize;

        sendSpeeds();
    }

    if (key && key.name == 'right') {
        servosSpeed[0] += stepSize;
        servosSpeed[1] += stepSize;
        servosSpeed[2] += stepSize;
        servosSpeed[3] += stepSize;

        sendSpeeds();
    }

    if (key && key.name == 'w') {
        request('http://' + ip + '/?wall=0', function (error, response, body) { });


        sendSpeeds();
    }
});

process.stdin.setRawMode(true);
process.stdin.resume();