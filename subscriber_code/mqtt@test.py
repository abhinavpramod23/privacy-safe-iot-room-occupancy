import paho.mqtt.client as mqtt  #importing so that we acn connect to the mqtt broker used in esp 

def on_connect(client, userdata, flags, rc):
    print("Connected with result code", rc)
    client.subscribe("hotel/room101/motion") # to receive messages from this topic so basically esp 

def on_message(client, userdata, msg):
    print("Received:", msg.payload) # prints the output 

client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message

client.connect("test.mosquitto.org", 1883, 60)
client.loop_forever()
