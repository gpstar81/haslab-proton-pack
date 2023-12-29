/**
 *   GPStar Attenuator - Ghostbusters Proton Pack & Neutrona Wand.
 *   Copyright (C) 2023 Michael Rajotte <michael.rajotte@gpstartechnologies.com>
 *                    & Dustin Grau <dustin.grau@gmail.com>
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, see <https://www.gnu.org/licenses/>.
 *
 */

#pragma once

const char SETTINGS_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<head>
  <meta name="viewport" content="width=device-width, initial-scale=1.0, maximum-scale=1.0, user-scalable=no">
  <title>Equipment Settings</title>
  <link rel="icon" href="data:;base64,iVBORw0KGgo=">
  <link rel="stylesheet" href="/style.css">
</head>
<body>
  <h1>Modify Equipment Settings</h1>
  <div class="block">
    <p>
      Change system configuration options using the available toggles/selectors.
      <br/>
      Options can only be changed when the pack and wand are not powered/running!
    </p>
    <br/>

    <h1>System Options</h1>
    <div class="block left">
      <b>System Mode:</b>
      <select id="systemMode" name="systemMode">
        <option value="0">Super Hero</option>
        <option value="1">Mode Original</option>
      </select>
      </br>
      <b>Theme Year:</b>
      <select id="themeYear" name="themeYear">
        <option value="1">System Toggle</option>
        <option value="2">1984</option>
        <option value="3">1989</option>
        <option value="4">Afterlife</option>
        <!-- <option value="5">Frozen Empire</option> -->
      </select>
      </br>
      <b>Default Master Volume:</b>
      <input type="range" id="masterVol" name="masterVol" min="0" max="100" value="100" step="2"/>
      </br>
      <b>Proton Stream Impact Effects:</b>
      <label class="switch">
        <input id="streamEffects" name="streamEffects" type="checkbox">
        <span class="slider round"></span>
      </label>
      </br>
      <b>Smoke Effects:</b>
      <label class="switch">
        <input id="smokeEffects" name="smokeEffects" type="checkbox">
        <span class="slider round"></span>
      </label>
      </br>
      <b>Strobe N-Filter on Overheat:</b>
      <label class="switch">
        <input id="overheatStrobe" name="overheatStrobe" type="checkbox">
        <span class="slider round"></span>
      </label>
      </br>
      <b>Lights Off During Overheat:</b>
      <label class="switch">
        <input id="overheatLightOff" name="overheatLightOff" type="checkbox">
        <span class="slider round"></span>
      </label>
      </br>
      <b>Overheat Sync to Fan:</b>
      <label class="switch">
        <input id="overheatSync" name="overheatSync" type="checkbox">
        <span class="slider round"></span>
      </label>
      </br>
      <b>Demo Light Mode:</b>
      <label class="switch">
        <input id="demoEnabled" name="demoEnabled" type="checkbox">
        <span class="slider round"></span>
      </label>
    </div>

    <h1>Cyclotron Lid</h1>
    <div class="block left">
      <b>LED Count:</b>
      <select id="cycCount" name="cycCount">
        <option value="12">12 - Stock</option>
        <option value="20">20 - Frutto</option>
        <option value="40">40 - Ring</option>
      </select>
      <br/>
      <b>Spectral Custom Color (Hue):</b>
      <input type="range" id="cycHue" name="cycHue" min="2" max="254" value="254" step="2"/>
      <br/>
      <b>Spectral Custom Saturation:</b>
      <input type="range" id="cycSat" name="cycSat" min="2" max="254" value="254" step="2"/>
      <br/>
      <b>Direction:</b>
      <select id="cycDir" name="cycDir">
        <option value="0">Counter-Clockwise</option>
        <option value="1">Clockwise</option>
      </select>
      </br>
      <b>Center LEDs:</b>
      <select id="cycCenter" name="cycCenter">
        <option value="0">3 LED</option>
        <option value="1">1 LED</option>
      </select>
      </br>
      <b>Enable Video Game Colors:</b>
      <label class="switch">
        <input id="vgCyclotron" name="vgCyclotron" type="checkbox">
        <span class="slider round"></span>
      </label>
      <br/>
      <b>Simulate Ring:</b>
      <label class="switch">
        <input id="cycRing" name="cycRing" type="checkbox">
        <span class="slider round"></span>
      </label>
    </div>

    <h1>Cyclotron Cake</h1>
    <div class="block left">
      <b>LED Count:</b>
      <select id="cakeCount" name="cakeCount">
        <option value="12">12</option>
        <option value="23">23</option>
        <option value="24">24</option>
        <option value="35">35</option>
      </select>
      <br/>
      <b>Spectral Custom Color (Hue):</b>
      <input type="range" id="cakeHue" name="cakeHue" min="2" max="254" value="254" step="2"/>
      <br/>
      <b>Spectral Custom Saturation:</b>
      <input type="range" id="cakeSat" name="cakeSat" min="2" max="254" value="254" step="2"/>
      <br/>
      <b>Swap Red/Green LEDs (GRB):</b>
      <label class="switch">
        <input id="cakeGRB" name="cakeGRB" type="checkbox">
        <span class="slider round"></span>
      </label>
    </div>

    <h1>Power Cell</h1>
    <div class="block left">
      <b>LED Count:</b>
      <select id="pcCount" name="pcCount">
        <option value="13">13 - Stock</option>
        <option value="15">15 - Frutto</option>
      </select>
      <br/>
      <b>Spectral Custom Color (Hue):</b>
      <input type="range" id="pcHue" name="pcHue" min="2" max="254" value="254" step="2"/>
      <br/>
      <b>Spectral Custom Saturation:</b>
      <input type="range" id="pcSat" name="pcSat" min="2" max="254" value="254" step="2"/>
      </br>
      <b>Enable Video Game Colors:</b>
      <label class="switch">
        <input id="vgPowercell" name="vgPowercell" type="checkbox">
        <span class="slider round"></span>
      </label>
    </div>

    <br/>
    <a href="/">&laquo; Back</a>
    &nbsp;&nbsp;&nbsp;
    <button type="button" class="green" onclick="saveSettings()">Save</button>
  </div>

  <script type="application/javascript">
    window.addEventListener("load", onLoad);

    function onLoad(event) {
      getStatus();
      getPreferences();
    }

    function getPreferences() {
      var xhttp = new XMLHttpRequest();
      xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
          console.log(JSON.parse(this.responseText));
        }
      };
      xhttp.open("GET", "/preferences", true);
      xhttp.send();
    }

    function getStatus() {
      var xhttp = new XMLHttpRequest();
      xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
          // Use the current settings to determine what's configured.
          var data = JSON.parse(this.responseText);
        }
      };
      xhttp.open("GET", "/status", true);
      xhttp.send();
    }

    function saveSettings() {
      var body = JSON.stringify({name: value});

      var xhttp = new XMLHttpRequest();
      xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
          var jObj = JSON.parse(this.responseText);
          alert(jObj.status); // Always display status returned.
        }
      };
      xhttp.open("PUT", "/settings/update", true);
      xhttp.setRequestHeader("Content-Type", "application/json");
      xhttp.send(body);
    }
  </script>
</body>
</html>
)=====";