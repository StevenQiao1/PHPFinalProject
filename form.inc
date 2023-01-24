<?php

$courses =
	array(
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

// availability values for before school
$availableB = array(
	"monB" => "Monday Before School",
	"tueB" => "Tuesday Before School",
	"wedB" => "Wednesday Before School",
	"thuB" => "Thursday Before School",
	"friB" => "Friday Before School"
);

// availability values for during lunch
$availableL = array(
	"monL" => "Monday Lunch",
	"tueL" => "Tuesday Lunch",
	"wedL" => "Wednesday Lunch",
	"thuL" => "Thursday Lunch",
	"friL" => "Friday Lunch"

);

// availability values for after school
$availableA = array(
	"monA" => "Monday After School",
	"tueA" => "Tuesday After School",
	"wedA" => "Wednesday After School",
	"thuA" => "Thursday After School",
	"friA" => "Friday After School"
);

?>

<div id="tutorpage">

	<div id="tutorhero">
		<h1>Become a Tutor</h1>
	</div>

	<div id="tutorform">
		<form method='post' action='<?php echo htmlspecialchars($_SERVER["PHP_SELF"]); ?>'
			enctype='multipart/form-data'>

			<br>

			<label class='label' for='fname' id='fnameLabel'>First Name:</label><br>
			<input type='text' name='fname' id='fname' value='<?php echo $fname; ?>'>
			<span class="error">*
				<?php echo $fnameError; ?>
			</span>

			<br><br>

			<label class='label' for='lname'>Last Name:</label><br>
			<input type='text' name='lname' id='lname' value='<?php echo $lname; ?>'>
			<span class="error">*
				<?php echo $lnameError; ?>
			</span>

			<br><br>

			<label class='label' for='fileToUpload'>Profile Picture:</label>
			<span class='error'>*
				<?php echo $fileError; ?>
			</span><br>
			<input type='file' name='fileToUpload' id='fileToUpload'>

			<br><br>

			<label class='label'>Current Grade: </label>
			<span class="error">*
				<?php echo $gradeError; ?>
			</span><br>
			<input type='radio' name='grade' value='Grade 12' id='grade12' <?php if (isset($grade) && $grade == "Grade 12")
				echo "checked"; ?>>
			<label for='grade12'>Grade 12</label><br>
			<input type='radio' name='grade' value='Grade 11' id='grade11' <?php if (isset($grade) && $grade == "Grade 11")
				echo "checked"; ?>>
			<label for='grade11'>Grade 11</label><br>
			<input type='radio' name='grade' value='Grade 10' id='grade10' <?php if (isset($grade) && $grade == "Grade 10")
				echo "checked"; ?>>
			<label for='grade10'>Grade 10</label><br>
			<input type='radio' name='grade' value='Grade 9' id='grade9' <?php if (isset($grade) && $grade == "Grade 9")
				echo "checked"; ?>>
			<label for='grade9'>Grade 9</label>

			<br><br>

			<label class='label'>Courses I Can Tutor </label>
			<span class='error'>*
				<?php echo $courseError; ?>
			</span><br>

			<?php

			// displays acadeimc courses
			foreach ($courses as $class) {

				$check = "";
				$index = array_search($class, $courses); // finds index of specific course
			
				echo "<input type='checkbox' name='course[]' value='$index' id='$index'";

				// checks if box was previously checked
				if (isset($course)) {
					if (in_array($index, $_POST["course"])) {
						$check = "  checked  ";
					} // if
				} // if
				echo $check . ">";

				echo "<label for='$index'>$class</label><br>";
			} // foreach
			?>


			<br>
			<span class="error">*
				<?php echo $availabilityError; ?>
			</span>
			<table>
				<tr>
					<th></th>
					<th>Monday</th>
					<th>Tuesday</th>
					<th>Wednesday</th>
					<th>Thursday</th>
					<th>Friday</th>
				</tr>
				<tr>
					<th>Before School</th>
					<?php

					// displays first row of availability table (Before)
					foreach ($availableB as $time) {
						echo "<td>";
						$index = array_search($time, $availableB); // finds index of specific time
					
						echo "<input type='checkbox' name='availability[]' value='$index' id='$index'>";

						// checks if box was previously checked
						if (isset($availability)) {
							if (in_array($index, $availability)) {
								echo " checked >";
							} // if
						} // if
					

						echo "<label for='$index'> </label><br>";
						echo "</td>";
					} // foreach
					echo "</tr>";

					echo "<tr>";
					echo "<th>Lunch</th>";

					// displays second row of availability table (Lunch) 
					foreach ($availableL as $time) {
						echo "<td>";
						$index = array_search($time, $availableL); // finds index of specific time
					
						echo "<input type='checkbox' name='availability[]' value='$index' id='$index'>";

						// checks if box was previously checked
						if (isset($availability)) {
							if (in_array($index, $availability)) {
								echo " checked ";
							} // if
						} // if
					

						echo "<label for='$index'> </label><br>";
						echo "</td>";
					} // foreach
					echo "</tr>";

					echo "<tr>";
					echo "<th>After School</th>";

					// displays third row of availability table (After)
					foreach ($availableA as $time) {
						echo "<td>";
						$index = array_search($time, $availableA); // finds index of specific time
					
						echo "<input type='checkbox' name='availability[]' value='$index' id='$index'>";

						// checks if box was previously checked
						if (isset($availability)) {
							if (in_array($index, $availability)) {
								echo " checked ";
							} // if
						} // if
					

						echo "<label for='$index'> </label><br>";
						echo "</td>";
					} // foreach
					?>
				</tr>

			</table>


			<br>

			<label class='label' for='comment'>About Me:</label>
			<span class='error'>*
				<?php echo $commentError; ?>
			</span><br>
			<textarea id='comment' name='comment' rows='4' cols='50'><?php echo $comment; ?></textarea>

			<br><br>

			<input type="hidden" name="form" value="tutor">
			<button id="tutorsubmit" type="submit" onclick='save()'>Submit</button><br>
		</form>
	</div>
</div>