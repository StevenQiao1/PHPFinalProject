<?php
$jsonstring = "";
$file = "userprofiles.json";
$fetchuid = 0;

// gets requested tutor UID
if (isset($_GET["uid"])) {
	$fetchuid = $_GET["uid"];
} // if

// checks if userprofiles exists before continuing
if (file_exists($file)) {
	$jsonstring = file_get_contents($file);

	//decode the string from json to PHP array
	$phparray = json_decode($jsonstring, true);

	// prints specific tutor info based on requested UID
	for ($i = 1; $i <= count($phparray); $i++) {
		if ($fetchuid == $i) {
			$jsoncode = json_encode($phparray[$i - 1], JSON_PRETTY_PRINT);
			echo $jsoncode;
		} // if
	} // for
} // if

?>