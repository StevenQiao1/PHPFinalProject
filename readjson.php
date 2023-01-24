<?php

$courses = array(
	"cf9" => "Core French 9",
	"la9" => "English Language Arts 9",
	"ict9" => "Information and Communications Technology 9",
	"cn9" => "Mandarin 9",
	"ma9" => "Mathematics 9",
	"num9" => "Numeracy 9",
	"sci9" => "Science 9",
	"ss9" => "Social Studies 9",
	"esp9" => "Spanish 9",
	"cn10" => "Mandarin 10",
	"cw10" => "Creative Writing 10",
	"nm10" => "New Media 10",
	"sp10" => "Spoken Language 10",
	"esp10" => "Spanish 10",
	"ls10" => "Literary Studies 10",
	"fr10" => "French 10",
	"fpls10" => "English First Peoples Literary Studies 10",
	"fpnm10" => "English First Peoples New Media 10",
	"fpsl10" => "English First Peoples Spoken Language 10",
	"fpw10" => "English First Peoples Writing 10",
	"ma10" => "Foundations of Mathematics and Pre-calculus 10",
	"cp10" => "Web Development 10",
	"wma10" => "Workplace Mathematics 10",
	"sci10" => "Science 10",
	"ss10" => "Social Studies 10",
	"chem11" => "Chemistry 11",
	"cs11" => "Computer Science 11",
	"cp11" => "Computer Programming 11",
	"cw11" => "Creative Writing 11",
	"fplsnm11" => "English First Peoples: Literary Studies + New Media 11",
	"fplssl11" => "English First Peoples: Literary Studies + Spoken Language 11",
	"fplsw11" => "English First Peoples: Literary Studies + Writing 11",
	"esci11" => "Environmental Science 11",
	"ess11" => "Explorations in Social Studies 11",
	"fma11" => "Foundations of Mathematics 11",
	"fr11" => "French 11",
	"iit11" => "Introductory Italian 11",
	"it11" => "Italian 11",
	"lsci11" => "Life Sciences 11",
	"ls11" => "Literary Studies 11",
	"cn11" => "Mandarin 11",
	"nm11" => "New Media 11",
	"phy11" => "Physics 11",
	"pcma11" => "Pre-Calculus Mathematics 11",
	"psy11" => "Psychology 11",
	"esp11" => "Spanish 11",
	"sl11" => "Spoken Language 11",
	"wma11" => "Workplace Mathematics 11",
	"wh12" => "20th Century World History 12",
	"apcalc" => "Advanced Placement Calculus",
	"apcs" => "Advanced Placement Computer Science",
	"apeng" => "Advanced Placement English",
	"apphys" => "Advanced Placement Physics",
	"apstat" => "Advanced Placement Statistics",
	"bio12" => "Anatomy and Physiology 12",
	"fp12" => "BC First Peoples 12",
	"calc12" => "Calculus 12",
	"chem12" => "Chemistry 12",
	"clch12" => "Climate Change 12",
	"cocu12" => "Comparative Cultures 12",
	"cp12" => "Computer Programming 12 (Web Development 12)",
	"cs12" => "Computer Science 12",
	"cf12" => "Core French 12",
	"cw12" => "Creative Writing 12",
	"crim12" => "Criminology 12",
	"leng12" => "English 12 Studies Linear (ELL)",
	"fp12" => "English First Peoples 12",
	"eng12" => "English Studies 12",
	"fma12" => "Foundations of Mathematics 12",
	"geo12" => "Geometry 12",
	"law12" => "Law Studies 12",
	"ls12" => "Literary Studies 12",
	"cn12" => "Mandarin 12",
	"phygeo12" => "Physical Geography 12",
	"phy12" => "Physics 12",
	"pcma12" => "Pre-Calculus Mathematics 12",
	"esp12" => "Spanish 12"
);

$search = "";
$returnData = [];
$multipleCourses = [];
$counter = 0;
$returnDataCounter = 0;

// read json file into array of strings
$jsonstring = file_get_contents("userprofiles.json");

// save the json data as a PHP array
$phparray = json_decode($jsonstring, true);

// saves entered search data
if (isset($_GET["search"])) {
	$search = $_GET["search"];
} // if


// is search button pressed, search for specific profiles
if ($search != "") {
	$multipleCourses[0] = null;

	// searches userprofiles for tutors with specific first names and AboutMe's
	foreach ($phparray as $entry) {
		if (str_contains(strtolower($entry["fname"]), strtolower($search)) || str_contains(strtolower($entry["lname"]), strtolower($search)) || str_contains(strtolower($entry["comment"]), strtolower($search))) {
			$returnData[] = $entry;
		} // if
		
		if(str_contains(str_replace(" ", "", strtolower($entry["fname"]."".$entry["lname"])), str_replace(" ", "",strtolower($search)))){
			$returnData[] = $entry;
		}// if

		// convert course name to course abbreviation
		foreach ($courses as $courseValue => $courseName) {

			// checks for if search is actual course name
			if (str_replace(" ", "", strtolower($courseName)) == str_replace(" ", "", strtolower($search))) {
				$search = $courseValue;
			} // if

			// otherwise checks if any courses contains search
			else if (str_contains(strtolower($courseName), str_replace(" ", "", strtolower($search)))) {
				$multipleCourses[$counter] = $courseValue;
				$counter++;
			} // else if
		} // foreach

		// checks for multiple courses if search wasn't full course name
		if ($multipleCourses[0] != null) {
			for ($j = 0; $j < count($multipleCourses); $j++) {
				for ($i = 0; $i < count($entry["course"]); $i++) {
					if (str_contains($entry["course"][$i], $multipleCourses[$j])) {
						$returnData[] = $entry;
					} // if
				} // for
			} // for
		} // if

		// otherwise searches userprofiles for tutors tutoring specific courses by specific course names
		else {
			for ($i = 0; $i < count($entry["course"]); $i++) {
				if (str_contains($entry["course"][$i], $search)) {
					$returnData[] = $entry;
				} // if
			} // for
		} // else


		// searches userprofiles for tutors of a specific grade
		if (str_contains($entry["grade"], $search)) {
			$returnData[] = $entry;
		} // if


	} // foreach
} else {
	$returnData = $phparray;
} // if

function uniqueMultiDimArray($array, $key)
{

	$temp_array = array();

	$i = 0;

	$key_array = array();



	foreach ($array as $val) {

		if (!in_array($val[$key], $key_array)) {

			$key_array[$i] = $val[$key];

			$temp_array[$i] = $val;

		}

		$i++;

	}

	return $temp_array;

} //uniqueMultiDimArray

$returnData = uniqueMultiDimArray($returnData, 'UID');


$jsoncode = json_encode($returnData, JSON_PRETTY_PRINT);
echo ($jsoncode);

?>