<!DOCTYPE html>
<html lang="en">

<head>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">

	<title>Mount Doug Peer Tutoring</title>

	<!-- Get the ip address of the server -->
	<script>
		var ip = "<?php echo $_SERVER['SERVER_NAME']; ?>";
	</script>

	<!-- include an external style sheet -->
	<link rel="stylesheet" href="style.css">

	<!-- include an external JavaScript file -->
	<script src="myscript.js"></script>

	<link rel="icon" type="image/x-icon" href="images/ptlogo2.jpg">

	<link rel="preconnect" href="https://fonts.googleapis.com">
	<link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
	<link href="https://fonts.googleapis.com/css2?family=Lato&family=Playfair+Display&display=swap" rel="stylesheet">

</head>

<body>

	<div id="header">

		<div class='logo'>
			<a id="navlink" href="?page=1">
				<img id="navlogo" src="images/ptlogoround.png" alt="Mount Doug peer tutoring logo">
			</a>
			<a id="navhead" href="?page=1">Mount Doug Peer Tutoring</a>
		</div>

		<div id="nav">
			<input type="checkbox" class="toggle-menu">
			<div class="hamburger"></div>

			<ul class="menu">
				<li>
					<a href="?page=1">Home</a>
				</li>

				<li>
					<a href="?page=2">Become A Tutor</a>
				</li>

				<li>
					<a href="?page=3">Book A Tutor</a>
				</li>

				<li>
					<a href="?delete=true">Reset Gallery</a>
				</li>

				<li>
					<a href="downloadall.php" download>Download All</a>
				</li>
			</ul>
		</div>
	</div>