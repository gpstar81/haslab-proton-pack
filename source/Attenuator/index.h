const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<head>
  <meta name="viewport" content="width=device-width, initial-scale="1.0, user-scalable=no">
  <title>Proton Pack</title>

  <style>
    html { font-family: Tahoma, Verdana, Arial; display: inline-block;, margin: 0px auto; text-align: center; }
    body { margin-top: 10px; }
    h1 { color: #222; margin: 15px; }
    h3 { color: #333; margin: 10px; }
    p { font-size: 20px; margin-bottom: 5px; }
    .card{
      background: #ddd;
      box-sizing: border-box;
      box-shadow: 0px 2px 18px -4px rgba(0, 0, 0, 0.75);
      color: #444;
      margin: 10px 20px 10px 20px;
      max-width: 400px;
      min-height: 200px;
      padding: 10px 20px 10px 20px;
      text-align: left;
    }
    button {
      background-color: #555;
      border-radius: 8px;
      box-shadow: 0 8px 16px 0 rgba(0,0,0,0.2), 0 6px 20px 0 rgba(0,0,0,0.19);
      color: white;
      margin: 5px;
      padding: 10px 24px;
      max-width: 100px;
      width: 120px;
    }
    .blue {
      background-color: #008CBA;
      border: 2px solid #006C9A;
    }
    .green {
      background-color: #4CAF50;
      border: 2px solid #2C8F30;
    }
    .red {
      background-color: #f44336;
      border: 2px solid #d42316;
    }
  </style>

  <script type="application/javascript">
    setInterval(function() {
      getStatus(); // Check for new data every X seconds
    }, 1000);

    function getStatus() {
      var xhttp = new XMLHttpRequest();
      xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
          var jObj = JSON.parse(this.responseText);
          document.getElementById("theme").innerHTML = jObj.theme || "...";
          document.getElementById("mode").innerHTML = jObj.mode || "...";
          document.getElementById("pack").innerHTML = jObj.pack || "...";
          document.getElementById("power").innerHTML = jObj.power || "...";
          document.getElementById("wand").innerHTML = jObj.wand || "...";
          document.getElementById("cable").innerHTML = jObj.cable || "...";
          document.getElementById("cyclotron").innerHTML = jObj.cyclotron || "...";
          document.getElementById("temperature").innerHTML = jObj.temperature || "...";
        }
      };
      xhttp.open("GET", "/status", true);
      xhttp.send();
    }

    function packOn() {
      var xhttp = new XMLHttpRequest();
      xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
          // alert(this.responseText);
        }
      };
      xhttp.open("GET", "/pack/on", true);
      xhttp.send();
    }

    function packOff() {
      var xhttp = new XMLHttpRequest();
      xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
          // alert(this.responseText);
        }
      };
      xhttp.open("GET", "/pack/off", true);
      xhttp.send();
    }

    function cancelWarning() {
      var xhttp = new XMLHttpRequest();
      xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
          // alert(this.responseText);
        }
      };
      xhttp.open("GET", "/pack/cancel", true);
      xhttp.send();
    }

    function toggleMute() {
      var xhttp = new XMLHttpRequest();
      xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
          // alert(this.responseText);
        }
      };
      xhttp.open("GET", "/volume/mute", true);
      xhttp.send();
    }

    function volumeMasterUp() {
      var xhttp = new XMLHttpRequest();
      xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
          // alert(this.responseText);
        }
      };
      xhttp.open("GET", "/volume/master/up", true);
      xhttp.send();
    }

    function volumeMasterDown() {
      var xhttp = new XMLHttpRequest();
      xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
          // alert(this.responseText);
        }
      };
      xhttp.open("GET", "/volume/master/down", true);
      xhttp.send();
    }

    function volumeEffectsUp() {
      var xhttp = new XMLHttpRequest();
      xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
          // alert(this.responseText);
        }
      };
      xhttp.open("GET", "/volume/effects/up", true);
      xhttp.send();
    }

    function volumeEffectsDown() {
      var xhttp = new XMLHttpRequest();
      xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
          // alert(this.responseText);
        }
      };
      xhttp.open("GET", "/volume/effects/down", true);
      xhttp.send();
    }

    function toggleMusic() {
      var xhttp = new XMLHttpRequest();
      xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
          // alert(this.responseText);
        }
      };
      xhttp.open("GET", "/music/toggle", true);
      xhttp.send();
    }

    function musicNext() {
      var xhttp = new XMLHttpRequest();
      xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
          // alert(this.responseText);
        }
      };
      xhttp.open("GET", "/music/next", true);
      xhttp.send();
    }

    function musicPrev() {
      var xhttp = new XMLHttpRequest();
      xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
          // alert(this.responseText);
        }
      };
      xhttp.open("GET", "/music/prev", true);
      xhttp.send();
    }
  </script>
</head>
<body>
  <h1>Equipment Status</h1>
  <div class="card">
    <p><b>Operating Mode:</b> <span id="theme">...</span></p>
    <p><b>Device Mode:</b> <span id="mode">...</span></p>
    <p><b>Pack State:</b> <span id="pack">...</span></p>
    <p><b>Power Level:</b> <span id="power">...</span></p>
    <p><b>Neutrona Wand:</b> <span id="wand">...</span></p>
    <p><b>Ribbon Cable:</b> <span id="cable">...</span></p>
    <p><b>Cyclotron State:</b> <span id="cyclotron">...</span></p>
    <p><b>Overheat State:</b> <span id="temperature">...</span></p>
  </div>
  <br/>
  <h1>Audio Controls</h1>
  <h3>Master Volume</h3>
  <button type="button" class="blue" onclick="volumeMasterUp()">Up +</button>
  <button type="button" onclick="toggleMute()">Mute/Unmute</button>
  <button type="button" class="blue" onclick="volumeMasterUp()">Down -</button>
  <br/>
  <h3>Music Playback</h3>
  <button type="button" class="blue" onclick="musicPrev()">&laquo; Prev</button>
  <button type="button" class="green" onclick="toggleMusic()">Start/Stop</button>
  <button type="button" class="blue" onclick="musicNext()">Next &raquo;</button>
  <br/>
  <h3>Effects Volume</h3>
  <button type="button" class="blue" onclick="volumeEffectsUp()">Up +</button>
  <button type="button" class="blue" onclick="volumeEffectsDown()">Down -</button>
  <br/>
  <br/>
  <h1>Pack Controls</h1>
  <button type="button" class="green" onclick="packOn()">Pack On</button>
  <button type="button" onclick="cancelWarning()">Cancel</button>
  <button type="button" class="red" onclick="packOff()">Pack Off</button>
</body>
</html>
)=====";