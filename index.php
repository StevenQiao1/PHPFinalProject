<?php
include "functions.php";

$fnameError = $lnameError = $gradeError = $courseError = $availabilityError = $commentError = $fileError = "";
$fname = $lname = $grade = $comment = $fileName = "";
$course;
$isValid = true;
$currentPage = 0;
$target_dir = "profileimages/";

if (isset($_GET["page"])) {
	$currentPage = $_GET["page"];
} // if

$dir = "profileimages/";
$dest = "thumbnails/";

// delete all existing json, identifier and image stored on the server
if (isset($_GET["delete"])) {

	if (file_exists("userprofiles.json")) {
		unlink("userprofiles.json");
	} //if

	if (file_exists("tuteeprofiles.json")) {
		unlink("tuteeprofiles.json");
	} //if

	if (file_exists("identifier.txt")) {
		unlink("identifier.txt");
	} //if

	if ($dh = opendir($dir)) {
		while (($file = readdir($dh)) !== false) {
			if ($file != "." && $file != "..") {
				unlink($dir . $file);
			} // if
		} //while
		closedir($dh);
	} //if

	if ($dh = opendir($dest)) {
		while (($file = readdir($dh)) !== false) {
			if ($file != "." && $file != "..") {
				unlink($dest . $file);
			} //if
		} //while
		closedir($dh);
	} //if

} //if

// error checking for tutor form
if ($_SERVER["REQUEST_METHOD"] == "POST" && $_POST["form"] == "tutor") {

	// check first name
	if (empty($_POST["fname"])) {
		$fnameError = "First name is required";
		$isValid = false;
	} else {
		$fname = test_input($_POST["fname"]);

		if (!preg_match("/^[a-zA-Z-' ]*$/", $fname)) {
			$fnameError = "Only letters and white space allowed";
			$isValid = false;
		} //if
	} //if

	//check last name
	if (empty($_POST["lname"])) {
		$lnameError = "Last name is required";
		$isValid = false;
	} else {
		$lname = test_input($_POST["lname"]);

		if (!preg_match("/^[a-zA-Z-' ]*$/", $lname)) {
			$lnameError = "Only letters and white space allowed";
			$isValid = false;
		} // if
	} //if

	//check grade
	if (empty($_POST["grade"])) {
		$gradeError = "Current Grade is required";
		$isValid = false;
	} else {
		$grade = $_POST["grade"];
	} //if

	// check course
	if (empty($_POST["course"])) {
		$courseError = "Courses are required";
		$isValid = false;
	} else {
		$course = $_POST["course"];
	} //if

	// check availability
	if (empty($_POST["availability"])) {
		$availabilityError = "Availability is required";
		$isValid = false;
	} else {
		$availability = $_POST["availability"];
	} //if

	// check comment
	if (empty($_POST["comment"])) {
		$commentError = "A brief comment about yourself is required";
		$isValid = false;
	} else {
		$comment = test_input($_POST["comment"]);

		if (!preg_match("/^[a-zA-Z_0-9\. \, \! \? \% \$ \&' ]*$/", $comment)) {
			$commentError = "Only letters and white space allowed";
			$isValid = false;
		} //if
	} //if

	// check image
	if (empty($_FILES["fileToUpload"]["name"])) {
		$fileError = "Sorry, you have to upload a profile picture.";
		$isValid = false;
	} else {
		if (!is_dir($target_dir)) {
			mkdir($target_dir);
		} // if

		if (!is_dir($dest)) {
			mkdir($dest);
		} // if

		$target_file = $target_dir . basename($_FILES["fileToUpload"]["name"]);
		$imageFileType = strtolower(pathinfo($target_file, PATHINFO_EXTENSION));
		$check = getimagesize($_FILES["fileToUpload"]["tmp_name"]);

		if ($check == false) {
			$fileError = "Sorry, this file is not an image.";
			$isValid = false;
		} //if

		if ($_FILES["fileToUpload"]["size"] > 4000000) {
			$fileError = "Sorry, your file is too large.";
			$isValid = false;
		} //if
		if ($imageFileType != "jpg" && $imageFileType != "png" && $imageFileType != "jpeg" && $imageFileType != "gif") {
			$fileError = "Sorry, only JPG, JPEG, PNG & GIF files are allowed.";
			$isValid = false;
		} //if
		if (file_exists($target_file)) {
			$fileError = "Sorry, file already exists.";
			$isValid = false;
		} //if

		if (file_exists("identifier.txt")) {
			$uid = trim(file_get_contents("identifier.txt"));
		} else {
			$uid = 1;
			file_put_contents("identifier.txt", 1);
		} //if

		// stores original image and create thumbnail with UID
		if ($isValid) {
			$target_file = $target_dir . $uid . "." . $imageFileType;
			move_uploaded_file($_FILES["fileToUpload"]["tmp_name"], $target_file);
			$_POST["UID"] = $uid;
			$_POST["imagetype"] = $imageFileType;
			$uid++;
			file_put_contents("identifier.txt", $uid);
			include "createthumbnail.php";

			$dir = "profileimages/";

			if ($dh = opendir($dir)) {
				while (($file = readdir($dh)) !== false) {
					if ($file != "." && $file != "..") {

						$src = $dir . $file;

						$dest = "thumbnails/" . $file;

						if (!file_exists($dest)) {
							createThumbnail($src, $dest, 240, 240);
						} // if
					} // if
				} //while
			} //if
		} //if
	} //if
} //if

// error checking for tutee form
if ($_SERVER["REQUEST_METHOD"] == "POST" && $_POST["form"] == "tutee") {

	// check first name
	if (empty($_POST["fname"])) {
		$fnameError = "First name is required";
		$isValid = false;
	} else {
		$fname = test_input($_POST["fname"]);

		if (!preg_match("/^[a-zA-Z-' ]*$/", $fname)) {
			$fnameError = "Only letters and white space allowed";
			$isValid = false;
		} //if
	} //if

	// check last name
	if (empty($_POST["lname"])) {
		$lnameError = "Last name is required";
		$isValid = false;
	} else {
		$lname = test_input($_POST["lname"]);

		if (!preg_match("/^[a-zA-Z-' ]*$/", $lname)) {
			$lnameError = "Only letters and white space allowed";
			$isValid = false;
		} //if
	} //if

	// check grade
	if (empty($_POST["grade"])) {
		$gradeError = "Current Grade is required";
		$isValid = false;
	} else {
		$grade = $_POST["grade"];
	} //if

	// check course
	if (empty($_POST["course"])) {
		$courseError = "Courses are required";
		$isValid = false;
	} else {
		$file = "userprofiles.json"; // read json file into array of strings
		$jsonstring = file_get_contents($file);
		$phparray = json_decode($jsonstring, true);
		$canTutor = false;
		$tutorInfo = explode(" ", $_POST['booked']);

		for ($i = 0; $i < count($phparray); $i++) {
			if ($phparray[$i]['fname'] == $tutorInfo[0] && $phparray[$i]['lname'] == $tutorInfo[1]) {
				foreach ($phparray[$i]['course'] as $currentCourse) {
					if ($currentCourse == $_POST['course'][0]) {
						$canTutor = true;
						break;
					} // if
				} //foreach
			} //if
		} //for

		if ($canTutor == true) {
			$course = $_POST["course"];
		} else {
			$courseError = "Tutor cannot tutor selected course";
			$isValid = false;
		} //if
	} //if

} // if



// save tutor or tutee information from submitted form
if ($isValid && $_SERVER["REQUEST_METHOD"] == "POST" && $_POST["form"] == "tutor") {

	// save tutor information
	$file = "userprofiles.json"; // read json file into array of strings

	if (file_exists($file)) {
		$jsonstring = file_get_contents($file);

		//decode the string from json to PHP array
		$phparray = json_decode($jsonstring, true);
	} // if

	unset($_POST['form']); // remove the form field from the $_POST array
	$phparray[] = $_POST; // add form submission to data

	$jsoncode = json_encode($phparray, JSON_PRETTY_PRINT); // encode the php array to formatted json 

	file_put_contents($file, $jsoncode); // write the json to the file
} else if ($isValid && $_SERVER["REQUEST_METHOD"] == "POST" && $_POST["form"] == "tutee") {

	// save tutee information
	$tuteefile = "tuteeprofiles.json";

	if (file_exists($tuteefile)) {
		$jsonstring = file_get_contents($tuteefile);

		//decode the string from json to PHP array
		$phparray2 = json_decode($jsonstring, true);
	} // if

	unset($_POST['form']); // remove the form field from the $_POST array
	$phparray2[] = $_POST; // add form submission to data

	$jsoncode = json_encode($phparray2, JSON_PRETTY_PRINT); // encode the php array to formatted json 

	file_put_contents($tuteefile, $jsoncode); // write the json to the file

} // if

include "header.inc";

if (!$isValid && $_SERVER["REQUEST_METHOD"] == "POST" && $_POST["form"] == "tutor") {
	include "form.inc";
} else if (!$isValid && $_SERVER["REQUEST_METHOD"] == "POST" && $_POST["form"] == "tutee") {
	include "booking.inc";
} else if ($isValid && $_SERVER["REQUEST_METHOD"] == "POST") {
	include "home.inc";
} else if ($currentPage == 1) {
	include "home.inc";
} else if ($currentPage == 2) {
	include "form.inc";
} else if ($currentPage == 3) {
	include "booking.inc";
} else {
	include "home.inc";
} //if

include "footer.inc";
?>