const express = require('express');
const app = express();

const mqtt = require("mqtt");
const connexion = mqtt.connect("mqtt://b2ec5fb1:08dddf858eb2a12c@broker.shiftr.io");

app.get('/', (req, res) => res.sendFile(__dirname + '/index.html'))
app.listen(3000, () => console.log('Example app listening on port 3000!'))


connexion.on("message", function(topic, message){
	if(topic == "Temperature"){
		console.log(topic + " : " + message);
	}
})

connexion.on("connect", function(){
	console.log("Connexion OK")
})

connexion.subscribe("/home/garden/fountain");


