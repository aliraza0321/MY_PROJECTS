 // Select elements
let countDisplay = document.querySelector(".count");
let incrementButton = document.querySelector("#increase");
let decrementButton = document.querySelector("#decrease");
let resetButton = document.querySelector("#reset");

// Initialize counter
let value = 0;
countDisplay.textContent = value;

// Increment
incrementButton.addEventListener("click", () => {
  value++;
  countDisplay.textContent = value;
  if(value>=0)
    {
    countDisplay.style.color = "black";
  }
});

// Decrement
decrementButton.addEventListener("click", () => {
  value--;
  countDisplay.textContent = value;
  if(value<0){
    countDisplay.style.color = "red";
  }
});

// Reset
resetButton.addEventListener("click", () => {
  value = 0;
  countDisplay.textContent = value;
  
});
