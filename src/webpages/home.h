/*
  +----------------------------------------------------------------------+
  | CoogleIOT for ESP8266                                                |
  +----------------------------------------------------------------------+
  | Copyright (c) 2017 John Coggeshall                                   |
  +----------------------------------------------------------------------+
  | Licensed under the Apache License, Version 2.0 (the "License");      |
  | you may not use this file except in compliance with the License. You |
  | may obtain a copy of the License at:                                 |
  |                                                                      |
  | http://www.apache.org/licenses/LICENSE-2.0                           |
  |                                                                      |
  | Unless required by applicable law or agreed to in writing, software  |
  | distributed under the License is distributed on an "AS IS" BASIS,    |
  | WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or      |
  | implied. See the License for the specific language governing         |
  | permissions and limitations under the License.                       |
  +----------------------------------------------------------------------+
  | Authors: John Coggeshall <john@coggeshall.org>                       |
  +----------------------------------------------------------------------+
*/

#ifndef COOGLEIOT_WEBPAGES_HOME_H_
#define COOGLEIOT_WEBPAGES_HOME_H_

const char WEBPAGE_Home[] PROGMEM = R"=====(
<html>
  <head>
    <title>CoogleIOT Firmware</title>
    <link href="/css" type="text/css" rel="stylesheet">
    <meta name="viewport" content="width=device-width, initial-scale=1">
  </head>
  <body>
    <h3>CoogleIOT Device Setup</h3>
    <div class="tabs" style="margin-top: 5px; margin-bottom: 5px;">
      <input type="radio" name="navtabs" id="tab1" checked="" aria-hidden="true">
      <label for="tab1" aria-hidden="true">WiFi</label>
        <div style="height: 600px">
         <fieldset>
           <legend>Device Wireless Setup</legend>
             <p>Settings for the device WiFi (as AP)</p>
             <div class="input-group fluid">
               <label aria-hidden="true" for="ap_name">Device AP SSID</label>
               <input aria-hidden="true" type="text" value="{{ap_name}}" id="ap_name" placeholder="Device AP Name">
             </div>
             <div class="input-group fluid">
               <label aria-hidden="true" for="ap_password">Device AP Password</label>
               <input aria-hidden="true" type="password" value="{{ap_password}}" id="ap_password">
             </div>
         </fieldset>
         <fieldset>
           <legend>Client WiFi Setup</legend>
           <p>Settings for WiFi (as Client)</p>
           <div class="input-group fluid">
             <label aria-hidden="true" for="ap_remote_name">Remote SSID</label>
             <input aria-hidden="true" type="text" value="{{remote_ap_name}}" id="ap_remote_name" placeholder="Remote AP Name">
           </div>
           <div class="input-group fluid">
              <label aria-hidden="true" for="ap_remote_password">Remote SSID Password</label>
              <input aria-hidden="true"type="password" value="{{remote_ap_password}}" id="ap_remote_password">
           </div>
         </fieldset>
      </div>
      <input type="radio" name="navtabs" id="tab2" aria-hidden="true">
      <label for="tab2" aria-hidden="true">MQTT</label>
      <div style="height: 600px">
        <fieldset>
          <legend>MQTT Client Configuration</legend>
          <div class="input-group fluid">
            <label aria-hidden="true" for="mqtt_host">MQTT Host</label>
            <input aria-hidden="true" type="text" value="{{mqtt_host}}" id="mqtt_host" placeholder="mqtt.example.com">
          </div>
          <div class="input-group fluid">
            <label aria-hidden="true" for="mqtt_port">MQTT Port</label>
            <input aria-hidden="true" type="text" value="{{mqtt_port}}" id="mqtt_port" placeholder="1883">
          </div>
          <div class="input-group fluid">
            <label aria-hidden="true" for="mqtt_username">MQTT Username</label>
            <input aria-hidden="true" type="text" value="{{mqtt_username}}" id="mqtt_username" placeholder="coogleiot">
          </div>
          <div class="input-group fluid">
            <label aria-hidden="true" for="mqtt_password">MQTT Pasword</label>
            <input aria-hidden="true" type="password" id="mqtt_password" value="{{mqtt_password}}">
          </div>
          <div class="input-group fluid">
            <label aria-hidden="true" for="mqtt_client_id">MQTT Client ID</label>
            <input aria-hidden="true" type="text" value="{{mqtt_client_id}}" id="mqtt_client_id" placeholder="my-client-id">
          </div>
        </fieldset>
      </div>
      <input type="radio" name="navtabs" id="tab3" aria-hidden="true">
      <label for="tab3" aria-hidden="true">System</label>
      <div style="height: 600px">
        <h3>System Commands</h3>
        <button class="secondary large" id="resetEEPROMBtn">Reset EEPROM (factory reset)</button>
        <button class="primary large" id="reloadBtn">Reboot</button>
        <fieldset>
          <legend>Firmware Updates</legend>
            <p>Device will check for updates every 30 minutes at this URL. See:<br><br>
            <a href="http://esp8266.github.io/Arduino/versions/2.0.0/doc/ota_updates/ota_updates.html#http-server">http://esp8266.github.io/Arduino/versions/2.0.0/doc/ota_updates/ota_updates.html#http-server</a><br><br>
            For details on the server-side implementation.</p>
          <div class="input-group fluid">
            <label aria-hidden="true" for="firmware_url">Firmware Update URL</label>
            <input aria-hidden="true" type="text" value="{{firmware_url}}" id="firmware_url" placeholder="http://example.com/updateEndpoint.php">
          </div>
          <p>Alternatively, you can directly upload a new .bin firmware file below:</p>
          <div class="input-group fluid">
            <form action="/firmware-upload" method="POST" enctype="multipart/form-data">
              <input type="file" id="firmware_file" name="update" accept=".bin">
              <label aria-hidden="true" for="firmware_file" class="button">Step 1: Select Firmware</label>
              <input type="submit" value="Step 2: Begin Upload">
            </form>
          </div>
        </fieldset>
      </div>
      <input type="radio" name="navtabs" id="tab4" aria-hidden="true">
      <label for="tab4" aria-hidden="true">Status</label>
      <div style="height: 600px">
        <table class="horizontal">
          <caption>CoogleIOT Status</caption>
          <thead>
            <tr>
              <th>CoogleIOT Version</th>
              <th>Build Date/Time</th>
              <th>CoogleIOT AP Status</th>
              <th>CoogleIOT AP SSID</th>
              <th>WiFi Status</th>
              <th>WiFi SSID</th>
              <th>LAN IP Address</th>
              <th>MQTT Status</th>
              <th>NTP Status</th>
              <th>DNS Status</th>
              <th>Firmware Updates</th>
            </tr>
         </thead>
         <tbody>
           <tr>
             <td data-label="CoogleIOT Version">{{coogleiot_version}}</td>
             <td data-label="Build Date/Time">{{coogleiot_buildtime}}</td>
             <td data-label="CoogleIOT AP Status">{{coogleiot_ap_status}}</td>
             <td data-label="CoogleIOT AP SSID">{{coogleiot_ap_ssid}}</td>
             <td data-label="WiFi Status">{{wifi_status}}</td>
             <td data-label="WiFi SSID">{{remote_ap_name}}</td>
             <td data-label="LAN IP Address">{{wifi_ip_address}}</td>
             <td data-label="MQTT Status">{{mqtt_status}}</td>
             <td data-label="NTP Status">{{ntp_status}}</td>
             <td data-label="DNS Status">{{dns_status}}</td>
             <td data-label="Firmware Updates">{{firmware_update_status}}</td>
           </tr>
         </tbody>
        </table>
      </div>
      <input type="radio" name="navtabs" id="tab5" aria-hidden="true">
      <label for="tab5" aria-hidden="true">Logs</label>
      <div style="height: 600px;">
        <div style="text-align: right;"><button class="primary" type="button" id="refreshLogBtn">Refresh Log</button></div>
        <hr/>
        <pre id="logContent" style="overflow-y: scroll; max-height: 470px; height: 470px;"></pre>
      </div>
    </div>
    <button class="primary bordered" style="width: 100%" id="saveBtn">Save and Restart</button>
	<script src="/jquery"></script>
    <script>
      $(document).ready(function() {
        
        var loadLog = function()
        {
           $.get('/logs', function(result) {
              $('#logContent').html(result);
              $('#logContent').scrollTop($('#logContent')[0].scrollHeight);
           });
        };
        
        $('#tab5').on('click', loadLog);
        $('#refreshLogBtn').on('click', loadLog);

        $('#resetEEPROMBtn').on('click', function(e) {
           window.location.href = '/reset';
        });

        $('#reloadBtn').on('click', function(e) {
           window.location.href = '/restart';
        });

        $('#saveBtn').on('click', function(e) {
          e.preventDefault();
          
          var postData = {
            'ap_name' : $('#ap_name').val(),
            'ap_password' : $('#ap_password').val(),
            'remote_ap_name' : $('#ap_remote_name').val(),
            'remote_ap_password' : $('#ap_remote_password').val(),
            'mqtt_host' : $('#mqtt_host').val(),
            'mqtt_port' : $('#mqtt_port').val(),
            'mqtt_username' : $('#mqtt_username').val(),
            'mqtt_password' : $('#mqtt_password').val(),
            'mqtt_client_id' : $('#mqtt_client_id').val(),
            'firmware_url' : $('#firmware_url').val()
          }
          
          console.log(postData);
          
          $.post('/api/save', postData, function(result) {
            
            if(!result.status) {
              alert("Failed to save settings");
              return;
            }
            
            alert("Settings Saved!");
            
          });
        });
      });
    </script>
  </body>
</html>
)=====";


#endif /* COOGLEIOT_WEBPAGES_HOME_H_ */
