
var i = 0;
var txt = 'EEPIS\nSecurity Operation Center.'; /* The text */
var speed = 50; /* The speed/duration of the effect in milliseconds */
var hasStarted = false; // Ensure the effect starts only once

function typeWriter() {
  if (i < txt.length) {
    document.getElementById("start").innerHTML += txt.charAt(i);
    i++;
    setTimeout(typeWriter, speed);
  }
}

// Function to check if the element is in view
function checkInView() {
  const startElement = document.getElementById("start");
  const rect = startElement.getBoundingClientRect();
  const windowHeight = window.innerHeight;

  // Check if the element is within the viewport
  if (rect.top >= 0 && rect.top <= windowHeight && !hasStarted) {
    hasStarted = true; // Prevent multiple triggers
    typeWriter(); // Start the typing effect
  }
}

// Run checkInView on page load and scroll
document.addEventListener('DOMContentLoaded', checkInView);
window.addEventListener('scroll', checkInView);

