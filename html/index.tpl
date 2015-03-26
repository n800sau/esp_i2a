<html>
<head><title>Three M web server</title>

<meta name="viewport" content="width=device-width; initial-scale=1; maximum-scale=1; user-scalable=no;"/>
<meta name="MobileOptimized" content="width" />
<meta name="HandheldFriendly" content="true" />
<link rel="stylesheet" type="text/css" href="style.css">
<script src="control.js"></script>

</head>
<body>

<!-- 
<div id="main">
ESP8266 three_m site. This page has been loaded <b>%counter%</b> times.
<ul>
<li>If you haven't connected this device to your WLAN network now, you can <a href="/wifi">do so.</a></li>
</ul>
</p>
-->

<div id="state-msg-on"></div>
<div id="state-msg-off"></div>

<table class="cnt">
	<tr>
		<td>
			<span class="brect"></span>
		</td>
		<td>
			<div class="squaredOne">
				<input type="radio" value="None" id="mv-fwd" name="main"/>
				<label for="mv-fwd"></label>
			</div>
		</td>
		<td>
			<span class="brect"></span>
		</td>
		<td>
			<span class="brect"></span>
		</td>
		<td>
			<div class="squaredOne">
				<input type="radio" value="None" id="sh-up" name="level"/>
				<label for="sh-up"></label>
			</div>
		</td>
	</tr>
	<tr>
		<td>
			<div class="squaredOne">
				<input type="radio" value="None" id="t-left" name="main"/>
				<label for="t-left"></label>
			</div>
		</td>
		<td>
			<div class="squaredOne red">
				<input type="radio" value="None" id="mv-stop" name="main" checked="checked"/>
				<label for="mv-stop"></label>
			</div>
		</td>
		<td>
			<div class="squaredOne">
				<input type="radio" value="None" id="t-right" name="main"/>
				<label for="t-right"></label>
			</div>
		</td>
			<span class="brect"></span>
		<td>
			<span class="brect"></span>
		</td>
		<td>
			<div class="squaredOne red" onmousedown="seton()" onmouseup="setoff()">
				<input type="radio" value="None" id="sh-stop" name="level" checked="checked"/>
				<label for="sh-stop"></label>
			</div>
		</td>
	</tr>
	<tr>
		<td>
			<span class="brect"></span>
		</td>
		<td>
			<div class="squaredOne" onmousedown="seton()" onmouseup="setoff()">
				<input type="radio" value="None" id="mv-back" name="main"/>
				<label for="mv-back"></label>
			</div>
		</td>
		<td>
			<span class="brect"></span>
		</td>
		<td>
			<span class="brect"></span>
		</td>
		<td>
			<div class="squaredOne" onmousedown="seton()" onmouseup="setoff()">
				<input type="radio" value="None" id="sh-down" name="level"/>
				<label for="sh-down"></label>
			</div>
		</td>
	</tr>
</table>

</body>
</html>
