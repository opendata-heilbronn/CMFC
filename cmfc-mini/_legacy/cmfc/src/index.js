
const express = require('express')
const app = express()
var SerialPort = require('serialport');
var port = new SerialPort('/dev/ttyS0', 9600);

app.get('/', (req, res) => {

    var str = "set:s" + req.params.servo + ","+ req.params.speed + "\n";
    port.write(str);
    res.send("success");
});

app.listen(3000, () => {
    console.log('Example app listening on port 3000!')
});

port.on('open', showPortOpen);
port.on('data', readSerialData);
port.on('close', showPortClose);
port.on('error', showError);

function showPortOpen() {
    console.log('port open. Data rate: ' + port.baudRate);
 }
  
 function readSerialData(data) {
    console.log(data);
 }
  
 function showPortClose() {
    console.log('port closed.');
 }
  
 function showError(error) {
    console.log('Serial port error: ' + error);
 }




port.open();