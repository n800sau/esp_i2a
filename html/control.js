function seton(ev) {
	document.getElementById('state-msg-on').innerHTML = event.target.id + '-on';
	ev.target.classList.add("on");
}

function setoff(ev) {
	document.getElementById('state-msg-off').innerHTML = event.target.id + '-off';
	ev.target.classList.remove("on");
}
