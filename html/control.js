function send_command(command) {
	var request = new XMLHttpRequest();
	request.onreadystatechange = function() {
		if(request.readyState == 4)
		{
			if(request.status == 200) {
				var jsonObj = JSON.parse(request.responseText);
				document.getElementById("reply").innerHTML = command + ':' + jsonObj.result;
			} else {
				document.getElementById("reply").innerHTML = command + ':' + request.responseText;
			}
		}
	}
	request.open("GET", '/command/' + command, true);
	request.send();
}

function init() {
	document.getElementById("mv_stop").checked = 'checked';
	document.getElementById("sh_stop").checked = 'checked';
	send_command('mv_stop');
	send_command('sh_stop');
}

function command(elm) {
	send_command(elm.id);
}
