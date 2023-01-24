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
?>

<div id="home" class="unhidden">

	<div id="hero">
		<h1>Search Tutors</h1>
	</div>

	<div id="searchsection">
		<input type="text" id="search" placeholder="Search Tutors" onfocus="this.placeholder = ''"
			onblur="this.placeholder = 'Search Tutors'">

		<button id="findtutors" onclick="fetchData('text')">
			Find Tutors
		</button>

		<!--<button type="reset" id="clear">&times;</button>-->
	</div>

	<div id="main">

		<?php
		$dest = "thumbnails/";
		if (is_dir($dest)) {
			if ($dh = opendir($dest)) {
				while (($file = readdir($dh)) !== false) {
					if ($file != "." && $file != "..") {
						echo "<img src='$dest$file' alt='Picture of a Tutor' class='card' onclick='displayLightBox(\"\", \"$file\")'>";
					}// if

				}// while
				closedir($dh);
			}// if
		}// if
		?>

	</div>

	<div id="filtertutor">

		<img src='images/ptlogoround.png' id="ptlogo" alt="peer tutoring logo">

		<h3>Filters</h3>

		<button type='button' class='collapsible' onclick='loadmenu()'>Available Courses</button>
		<div class='content'>
			<?php

			$tutorsCanTutor = array(); // used to store an array of courses tutors can tutor
			
			$file = "userprofiles.json";
			if (file_exists($file)) {
				$jsonstring = file_get_contents($file);

				//decode the string from json to PHP array
				$phparray = json_decode($jsonstring, true);

				// load the list of courses tutor can tutor into the array
				for ($i = 0; $i < count($phparray); $i++) {
					for ($j = 0; $j < count($phparray[$i]['course']); $j++) {
						if (!in_array($phparray[$i]['course'][$j], $tutorsCanTutor)) {
							array_push($tutorsCanTutor, $phparray[$i]['course'][$j]);
						}// if
					}// for
				}// for
			}// if

			// sort the tutorsCanTutor according to the order of courses
			uasort($tutorsCanTutor, function ($a, $b) use ($courses) {
				$indexA = array_search($a, array_keys($courses));
				$indexB = array_search($b, array_keys($courses));
				return $indexA - $indexB;
			});

			// loops through each course tutor can tutor and list them with check boxes
			foreach ($tutorsCanTutor as $class) {
				$check = "";

				// $index = array_search($class, $courses);
				$courseName = $courses[$class];

				echo "<input type='radio' class='checkbox' name='course[]' value='$class' onclick='fetchData(this)' ";

				// checks the checkbox if the user has checked it previously
				if (isset($course)) {
					if (in_array($class, $_POST["course"])) {
						$check = "  checked  ";
					} // if
				} // if
			
				echo $check . ">";

				echo "<label>$courseName</label><br>";
			}// foreach

			?>
		</div>


		<button type='button' class='collapsible' onclick='loadmenu()'>Grade Levels</button>

		<div class='content'>
			<input type='radio' name='grade' value='Grade 12' onclick='fetchData(this)' id='grade12'>
			<label for="grade12">Grade 12</label><br>
			<input type='radio' name='grade' value='Grade 11' onclick='fetchData(this)' id='grade11'>
			<label for='grade11'>Grade 11</label><br>
			<input type='radio' name='grade' value='Grade 10' onclick='fetchData(this)' id='grade10'>
			<label for='grade10'>Grade 10</label><br>
			<input type='radio' name='grade' value='Grade 9' onclick='fetchData(this)' id='grade9'>
			<label for='grade9'>Grade 9</label>
		</div>
	</div>

</div>

<div id="lightbox" class="hidden">
</div>

<div id="positionBigImage" class="hidden">
	<a class="prevNext" id="left" onclick="prevNext('left')">&#10094;</a>
	<a class="prevNext" id="right" onclick="prevNext('right')"> &#10095;</a>
	<img id="bigImage" src="default-image.jpg" alt="" onclick="displayLightBox('','')">

	<div id="boundaryBigImage" class="hidden">
		<div id="info">
			<div id="cardlist">
				<div id="name"></div>
				<div id="grade"></div>
				<div id="aboutme"></div>
				<div id="courses"></div>
			</div>
			<div id="download"></div>

		</div>
	</div>

</div>