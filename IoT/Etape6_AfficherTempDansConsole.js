const mqtt = require("mqtt");
const connexion = mqtt.connect("mqtt://b2ec5fb1:08dddf858eb2a12c@broker.shiftr.io");


connexion.on("message", function(topic, message){
	if(topic == "Temperature"){
		console.log(topic + " : " + message);
	}
})

connexion.on("connect", function(){
	console.log("Connexion OK")
})

connexion.subscribe("/home/garden/fountain");


