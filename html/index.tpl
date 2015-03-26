<html>
<head><title>Three M web server</title>

<meta name="viewport" content="width=device-width; initial-scale=1; maximum-scale=1; user-scalable=no;"/>
<meta name="MobileOptimized" content="width" />
<meta name="HandheldFriendly" content="true" />
<link rel="stylesheet" type="text/css" href="style.css">
<script src="control.js"></script>

</head>
<body onload="init()">

<!-- 
<div id="main">
ESP8266 three_m site. This page has been loaded <b>%counter%</b> times.
<ul>
<li>If you haven't connected this device to your WLAN network now, you can <a href="/wifi">do so.</a></li>
</ul>
</p>
-->

<table class="cnt">
	<tr>
		<td>
			<span class="brect"></span>
		</td>
		<td>
			<div class="squaredOne">
				<input type="radio" value="None" id="mv_fwd" name="main" onclick="command(this)"/>
				<label for="mv_fwd"></label>
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
				<input type="radio" value="None" id="sh_up" name="level" onclick="command(this)"/>
				<label for="sh_up"></label>
			</div>
		</td>
	</tr>
	<tr>
		<td>
			<div class="squaredOne">
				<input type="radio" value="None" id="t_left" name="main" onclick="command(this)"/>
				<label for="t_left"></label>
			</div>
		</td>
		<td>
			<div class="squaredOne red">
				<input type="radio" value="None" id="mv_stop" name="main" checked="checked" onclick="command(this)"/>
				<label for="mv_stop"></label>
			</div>
		</td>
		<td>
			<div class="squaredOne">
				<input type="radio" value="None" id="t_right" name="main" onclick="command(this)"/>
				<label for="t_right"></label>
			</div>
		</td>
			<span class="brect"></span>
		<td>
			<span class="brect"></span>
		</td>
		<td>
			<div class="squaredOne red">
				<input type="radio" value="None" id="sh_stop" name="level" checked="checked" onclick="command(this)"/>
				<label for="sh_stop"></label>
			</div>
		</td>
	</tr>
	<tr>
		<td>
			<span class="brect"></span>
		</td>
		<td>
			<div class="squaredOne">
				<input type="radio" value="None" id="mv_back" name="main" onclick="command(this)"/>
				<label for="mv_back"></label>
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
				<input type="radio" value="None" id="sh_down" name="level" onclick="command(this)"/>
				<label for="sh_down"></label>
			</div>
		</td>
	</tr>
</table>

<div id="reply"></div>

</body>
</html>
