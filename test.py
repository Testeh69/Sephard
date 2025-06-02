from flask import Flask

app = Flask(__name__)

@app.route('/')
def home():
    return "Hello, world!"

if __name__ == '__main__':
    # Host 0.0.0.0 = écoute sur toutes les interfaces réseau (WiFi, Ethernet, etc.)
    app.run(host='0.0.0.0', port=5000)
