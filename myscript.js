var courseList =
{
	"cf9": "Core French 9",
	"la9": "English Language Arts 9",
	"ict9": "Information and Communications Technology 9",
	"cn9": "Mandarin 9",
	"ma9": "Mathematics 9",
	"num9": "Numeracy 9",
	"sci9": "Science 9",
	"ss9": "Social Studies 9",
	"esp9": "Spanish 9",
	"cn10": "Mandarin 10",
	"cw10": "Creative Writing 10",
	"nm10": "New Media 10",
	"sp10": "Spoken Language 10",
	"esp10": "Spanish 10",
	"ls10": "Literary Studies 10",
	"fr10": "French 10",
	"fpls10": "English First Peoples Literary Studies 10",
	"fpnm10": "English First Peoples New Media 10",
	"fpsl10": "English First Peoples Spoken Language 10",
	"fpw10": "English First Peoples Writing 10",
	"ma10": "Foundations of Mathematics and Pre-calculus 10",
	"cp10": "Web Development 10",
	"wma10": "Workplace Mathematics 10",
	"sci10": "Science 10",
	"ss10": "Social Studies 10",
	"chem11": "Chemistry 11",
	"cs11": "Computer Science 11",
	"cp11": "Computer Programming 11",
	"cw11": "Creative Writing 11",
	"fplsnm11": "English First Peoples: Literary Studies + New Media 11",
	"fplssl11": "English First Peoples: Literary Studies + Spoken Language 11",
	"fplsw11": "English First Peoples: Literary Studies + Writing 11",
	"esci11": "Environmental Science 11",
	"ess11": "Explorations in Social Studies 11",
	"fma11": "Foundations of Mathematics 11",
	"fr11": "French 11",
	"iit11": "Introductory Italian 11",
	"it11": "Italian 11",
	"lsci11": "Life Sciences 11",
	"ls11": "Literary Studies 11",
	"cn11": "Mandarin 11",
	"nm11": "New Media 11",
	"phy11": "Physics 11",
	"pcma11": "Pre-Calculus Mathematics 11",
	"psy11": "Psychology 11",
	"esp11": "Spanish 11",
	"sl11": "Spoken Language 11",
	"wma11": "Workplace Mathematics 11",
	"wh12": "20th Century World History 12",
	"apcalc": "Advanced Placement Calculus",
	"apcs": "Advanced Placement Computer Science",
	"apeng": "Advanced Placement English",
	"apphys": "Advanced Placement Physics",
	"apstat": "Advanced Placement Statistics",
	"bio12": "Anatomy and Physiology 12",
	"fp12": "BC First Peoples 12",
	"calc12": "Calculus 12",
	"chem12": "Chemistry 12",
	"clch12": "Climate Change 12",
	"cocu12": "Comparative Cultures 12",
	"cp12": "Computer Programming 12 (Web Development 12)",
	"cs12": "Computer Science 12",
	"cf12": "Core French 12",
	"cw12": "Creative Writing 12",
	"crim12": "Criminology 12",
	"leng12": "English 12 Studies Linear (ELL)",
	"fp12": "English First Peoples 12",
	"eng12": "English Studies 12",
	"fma12": "Foundations of Mathematics 12",
	"geo12": "Geometry 12",
	"law12": "Law Studies 12",
	"ls12": "Literary Studies 12",
	"cn12": "Mandarin 12",
	"phygeo12": "Physical Geography 12",
	"phy12": "Physics 12",
	"pcma12": "Pre-Calculus Mathematics 12",
	"esp12": "Spanish 12"
};

var storedImg = localStorage.getItem("storedImg");
var checkedArray = [];
var courseListDOM;

var coll = document.getElementsByClassName("collapsible");
var j;
function loadmenu() {
	for (j = 0; j < coll.length; j++) {
		coll[j].addEventListener("click", function () {
			this.classList.toggle("active");
			var content = this.nextElementSibling;
			if (content.style.maxHeight) {
				content.style.maxHeight = null;
			} else {
				content.style.maxHeight = content.scrollHeight + "px";
			} //if
		});
	} // for
} //loadmenu
function save() {
	var img = document.getElementById("fileToUpload");
	localStorage.setItem("storedImg", img);
} // save

// change the visibility of a div with divID
function changeVisibility(divID) {
	var element = document.getElementById(divID);

	// if element exists, swap its class name between hidden and unhidden
	if (element) {
		element.className = (element.className == 'hidden') ? 'unhidden' : 'hidden';
	} // if

} // changeVisibility

function displayLightBox(alt, imageFile) {
	var image = new Image();
	var bigImage = document.getElementById("bigImage");
	var requestedUid = imageFile.split(".")[0];

	image.src = "profileimages/" + imageFile;
	image.alt = alt;

	image.onload = function () {
		var width = image.width;
		document.getElementById("boundaryBigImage").style.width = width + "px";
	};

	bigImage.src = image.src;
	bigImage.alt = image.alt;
	bigImage.setAttribute("class", "card");

	changeVisibility('home');
	changeVisibility('lightbox');
	changeVisibility('boundaryBigImage');
	changeVisibility('positionBigImage');

	document.getElementById("left").style.display = "flex";
	document.getElementById("right").style.display = "flex";

	if (imageFile != "") {
		fetch("http://" + ip + "/~hanayeste/tutormd6/getData.php?uid=" + requestedUid)
			.then(response => response.json())
			.then(data => updateContents(data))
	} // if

} // displayLightBox

function updateContents(data) {
	console.log(data);

	document.getElementById("name").innerHTML = "<strong>Tutor's Name</strong>: " + data.fname + " " + data.lname;
	document.getElementById("grade").innerHTML = "<strong>Tutor's Grade</strong>: " + data.grade;

	let courses = "";

	for (let i = 0; i < data.course.length; i++) {
		for (var key in courseList) {
			if (key == data.course[i]) {
				courses += courseList[key] + "<br>";
			} // if
		} // for
	}// for

	document.getElementById("courses").innerHTML = "<strong>Tutor's Courses</strong>: <br>" + courses;
	document.getElementById("aboutme").innerHTML = "<strong>About Me</strong>: <br>" + data.comment;
	document.getElementById("download").innerHTML = "<button><a href='profileimages/" + data.UID + "." + data.imagetype + "' download> Download Image </a></button>";
} // updateContents

function togglemenu() {

	if (document.getElementById("navmobile").style.display == "grid") {
		document.getElementById("navmobile").style.display = "none";
	} else {
		document.getElementById("navmobile").style.display = "grid";
	}// if
} //togglemenu

function getCourses(element) {
	switch (element.type) {
		case "radio":
			checkedArray = [element.value]
			break;
		case "checkbox":
			if (element.checked == true) {
				checkedArray.push(element.value);
			} else {
				checkedArray.pop(element.value);
			}
			break;
		default:
			break;
	}
	// Course list needs to be reset to default before filtering.
	resetCourseList()
	filterCourses()
} // getCourses

function resetCourseList() {
	if(!courseListDOM) {
		// Clone initial dom state. Courselist without any filtering.
		courseListDOM = document.getElementById("booked").cloneNode(true);
	} else {
		// Resetting the dom to initial state. Courselist without any filtering.
		document.getElementById("booked").replaceWith(courseListDOM.cloneNode(true))
	}
}

function filterCourses() {
	// skip filtering if nothing has been checked.
	if(!checkedArray.length) {
		return
	}

	var coursesDom = document.getElementById("booked");
	for(var i = coursesDom.length - 1; i >= 0; i --) {
		var coursesStr = coursesDom[i].dataset.courses
		var coursesArr = coursesStr.split(",")
		var intersect = coursesArr.filter(value => checkedArray.includes(value))
		if(!intersect.length) {
			coursesDom.remove(i)
		}
	}
}

function fetchData(element) {

	if (element === "text") {
		var search = document.getElementById("search").value;
	} else {
		if (element.checked == true) {
			var search = element.value;
		} else {
			var search = "";
		} // if
	} // if

	document.getElementById("main").innerHTML = "";

	console.log(search);

	let searchURL = "http://" + ip + "/~hanayeste/tutormd6/readjson.php?search=" + search;

	console.log(searchURL);

	if (search.length > 0 && searchURL != null) {
		fetch("http://" + ip + "/~hanayeste/tutormd6/readjson.php?search=" + search)
			.then(response => response.json())
			.then(function (data) {
				let i;
				let main = document.getElementById("main");

				console.log(data);

				for (i in data) {
					let img = new Image();
					console.log(img.src);
					img.setAttribute("class", "card");
					img.src = "thumbnails/" + data[i].UID + "." + data[i].imagetype;
					img.alt = data[i].UID + "." + data[i].imagetype;
					img.setAttribute("onclick", "displayLightBox('" + img.alt + "', '" + data[i].UID + "." + data[i].imagetype + "')");
					document.getElementById("left").style.display = "flex";
					document.getElementById("right").style.display = "flex";
					main.appendChild(img);
				} // for
			});

	} else if (search.length == 0 || UrlExists(searchURL) == false) {
		emptySearchError();
	} //if
}// fetchData

function emptySearchError() {
	document.getElementById("main").innerHTML += "Sorry, your search input is invalid, please try again.";
} // emptySearchError

function showMessage(data) {
	document.getElementById("searchresults").innerHTML = data;
} // showMessage

function prevNext(movement) {
	let cards = document.getElementsByClassName("card");
	let bigImage = document.getElementById("bigImage");

	let i = 0;
	while (cards[i].getAttribute("alt") != bigImage.getAttribute("alt")) {
		++i;
	}// while

	if (movement == "right" && i < cards.length - 2) {
		++i;
	} else if (movement == "left" && i > 0) {
		--i;
	}// if

	displayLightBox("", "");
	displayLightBox(cards[i].getAttribute("alt"), cards[i].getAttribute("alt"));
} // prevNext

window.addEventListener('load', () => {
	const button = document.getElementById("clear");
	button.addEventListener('click', () => {
		document.getElementById("search").value = "";
	});
});

function UrlExists(url) {
	var http = new XMLHttpRequest();
	http.open('HEAD', url, false);
	http.send();
	if (http.status != 404) {
		return true;
		console.log("true");
	} else {
		return false;
		console.log("false");
	}
}