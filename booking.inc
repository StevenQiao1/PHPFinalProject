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



$available = array(
	"monB" => "Monday Before School",
	"tueB" => "Tuesday Before School",
	"wedB" => "Wednesday Before School",
	"thuB" => "Thursday Before School",
	"friB" => "Friday Before School",
	"monL" => "Monday Lunch",
	"tueL" => "Tuesday Lunch",
	"wedL" => "Wednesday Lunch",
	"thuL" => "Thursday Lunch",
	"friL" => "Friday Lunch",
	"monA" => "Monday After School",
	"tueA" => "Tuesday After School",
	"wedA" => "Wednesday After School",
	"thuA" => "Thursday After School",
	"friA" => "Friday After School"
);

?>

<div id="tuteepage">

	<div id="tuteehero">
		<h1>Book A Tutor</h1>
	</div>

	<div id='tuteeform'>
		<form method='post' action='<?php echo htmlspecialchars($_SERVER["PHP_SELF"]); ?>'
			enctype='multipart/form-data'>
			<br>

			<div class='formdiv'>

				<label class='label' for='fname'>First Name:</label><br>
				<input id='fname' type='text' name='fname' value='<?php echo $fname; ?>'>
				<span class="error">*
					<?php echo $fnameError; ?>
				</span>

				<br><br>

				<label class='label' for='lname'>Last Name:</label><br>
				<input id='lname' type='text' name='lname' value='<?php echo $lname; ?>'>
				<span class="error">*
					<?php echo $lnameError; ?>
				</span>

			</div>

			<br><br>

			<label class='label'>Current Grade: </label>
			<span class="error">*
				<?php echo $gradeError; ?>
			</span><br>
			<input type='radio' name='grade' value='12' id='grade12' <?php if (isset($grade) && $grade == "12")
				echo "checked"; ?>>
			<label for='grade12'>Grade 12</label><br>
			<input type='radio' name='grade' value='11' id='grade11' <?php if (isset($grade) && $grade == "11")
				echo "checked"; ?>>
			<label for='grade11'>Grade 11</label><br>
			<input type='radio' name='grade' value='10' id='grade10' <?php if (isset($grade) && $grade == "10")
				echo "checked"; ?>>
			<label for='grade10'>Grade 10</label><br>
			<input type='radio' name='grade' value='9' id='grade9' <?php if (isset($grade) && $grade == "9")
				echo "checked"; ?>>
			<label for='grade9'>Grade 9</label>

			<br><br>

			<label class='label'>Subjects</label>
			<span class='error'>*
				<?php echo $courseError; ?>
			</span><br>

			<?php


			$tutorsCanTutor = array(); // used to store an array of courses tutors can tutor
			$file = "userprofiles.json";

			
			// if no tutors available, noTutors is true
			if (!file_exists($file)) {
				$noTutors = true;
			} // if
			else {
				$noTutors = false;
			} // else
			
		
		
			// if userprofiles exists, load tutors into drop menu
			if (file_exists($file)) {
				$jsonstring = file_get_contents($file);

				//decode the string from json to PHP array
				$phparray = json_decode($jsonstring, true);

				// load the list of courses tutor can tutor into the array
				for ($i = 0; $i < count($phparray); $i++) {
					for ($j = 0; $j < count($phparray[$i]['course']); $j++) {
						if (!in_array($phparray[$i]['course'][$j], $tutorsCanTutor)) {
							array_push($tutorsCanTutor, $phparray[$i]['course'][$j]);
						} // if
					} // for
				} // for
			} // if

		
			// sort the tutorsCanTutor according to the order of courses
			uasort($tutorsCanTutor, function ($a, $b) use ($courses) {
				$indexA = array_search($a, array_keys($courses));
				$indexB = array_search($b, array_keys($courses));
				return $indexA - $indexB;
			});


			//loops through each course tutor can tutor and list them with check boxes
			foreach ($tutorsCanTutor as $class) {
				$check = "";
				$courseName = $courses[$class];

				echo "<input type='radio' class='checkbox' name='course[]' value='$class' onclick='getCourses(this) ' id='$class' ";

				//checks the checkbox if the user has checked it previously
				if (isset($course)) {
					if (in_array($class, $_POST["course"])) {
						$check = "  checked  ";
					} // if
				} //if
			
				echo $check . ">";

				echo "<label for='$class'>$courseName</label><br>";
			} // foreach
			
			$file = "tuteeprofiles.json"; // read json file into array of strings
			
			// checks for already booked tutors
			if (file_exists($file)) {
				$jsonstring = file_get_contents($file);

				//decode the string from json to PHP arrays
				$phparray2 = json_decode($jsonstring, true);

				$alreadyBooked = array(); // store already booked tutor and time
			
				//load the already booked array
				for ($i = 0; $i < count($phparray2); $i++) {
					$alreadyBooked[$i] = $phparray2[$i]['booked'];
				} // for
			} // if
			
			echo "<br><label for='booked'>Select Tutor and Time</label><br>";
			echo "<select class='select' name='booked' id='booked'>";
					
			// if tutors are available, insert options to drop menu
			if (!$noTutors) {

				//display drop box of available tutor and time
				for ($i = 0; $i < count($phparray); $i++) {

					// loops through each tutor's working time
					foreach ($phparray[$i]['availability'] as $time) {
						$value = $phparray[$i]['fname'] . " " . $phparray[$i]['lname'] . " " . $available[$time]; // tutor and time
						$invalidOption = false; // true if the tutor and time has been booked
			
						if(!empty($alreadyBooked)){
							//check if the value has already been booked
							foreach ($alreadyBooked as $temp) {
								if ($value == $temp) {
									$invalidOption = true;
								} // if
							} //foreach
						} // if
			
						//displays value as an option if it has not been booked
						$coursesCanTutor = implode(",", $phparray[$i]['course']);
						if (!$invalidOption) {
							echo "<option value='$value' data-courses='$coursesCanTutor'> $value </option>";
						} // if
					} //foreach 
				} // for
				
				echo "<input type='hidden' name='form' value='tutee'>";
				echo "<button id='tuteesubmit' type='submit' onclick='save()'>Submit</button><br>";
			} // if
			
			// otherwise display "No Tutors Available"
			else {
				echo "<option value='none'> No Tutors Available </option>";
			} // else
			echo "</select>";
			?>
		</form>
	</div>
</div>