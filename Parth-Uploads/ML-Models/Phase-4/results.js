var h,w,s,d;
function calculation(){
	
	h = Number(localStorage.getItem("Height"));
	localStorage.removeItem("Height");
	w = Number(localStorage.getItem("Weight"));
	localStorage.removeItem("Weight");
	s = Number(localStorage.getItem("Systolic"));
	localStorage.removeItem("Systolic");
	d = Number(localStorage.getItem("Diastolic"));
	localStorage.removeItem("Diastolic");
	
	
	var sum =  w / (h * h);
    if (sum < 18.5)
    {
    	document.getElementById("bmic").value = "Underweight";
    }
    else if (sum < 24.9)
    {
    	document.getElementById("bmic").value = "Normalweight";
    }
    else if (sum < 29.9)
    {
    	document.getElementById("bmic").value = "Overweight";
    }
    else if (sum < 30)
    {
    	document.getElementById("bmic").value = "Obese";
    }
	document.getElementById("bmi").value = sum;
	
	
	
	
	if (s < 120)
		{
			if (d < 80)
			{
		    	document.getElementById("b").value = "NORMAL";
			}
			else if (d < 90)
			{
		    	document.getElementById("b").value = "CAUTION";
			}
			else if (d < 100)
			{
		    	document.getElementById("b").value = "HIGH";
			}
			else if (d < 110)
			{
		    	document.getElementById("b").value = "VERY HIGH";
			}
			else
			{
		    	document.getElementById("b").value = "CRISIS";
			}
		}
		else if (s < 140)
		{
			if (d < 80)
			{
		    	document.getElementById("b").value = "CAUTION";
			}
			else if (d < 90)
			{
		    	document.getElementById("b").value = "CAUTION";
			}
			else if (d < 100)
			{
		    	document.getElementById("b").value = "HIGH";
			}
			else if (d < 110)
			{
		    	document.getElementById("b").value = "VERY HIGH";
			}
			else
			{
		    	document.getElementById("b").value = "CRISIS";
			}
		}
		else if (s < 160)
		{
			if (d < 80)
			{
		    	document.getElementById("b").value = "HIGH";
			}
			else if (d < 90)
			{
		    	document.getElementById("b").value = "HIGH";
			}
			else if (d < 100)
			{
		    	document.getElementById("b").value = "HIGH";
			}
			else if (d < 110)
			{
		    	document.getElementById("b").value = "VERY HIGH";
			}
			else
			{
		    	document.getElementById("b").value = "CRISIS";
			}
		}
		else if (s < 180)
		{
			if (d < 80)
			{
		    	document.getElementById("b").value = "VERY HIGH";
			}
			else if (d < 90)
			{
		    	document.getElementById("b").value = "VERY HIGH";
			}
			else if (d < 100)
			{
		    	document.getElementById("b").value = "VERY HIGH";
			}
			else if (d < 110)
			{
		    	document.getElementById("b").value = "VERY HIGH";
			}
			else
			{
		    	document.getElementById("b").value = "CRISIS";
			}
		}
		else
		{
			if (d < 80)
			{
		    	document.getElementById("b").value = "CRISIS";
			}
			else if (d < 90)
			{
		    	document.getElementById("b").value = "CRISIS";
			}
			else if (d < 100)
			{
		    	document.getElementById("b").value = "CRISIS";
			}
			else if (d < 110)
			{
		    	document.getElementById("b").value = "CRISIS";
			}
			else
			{
		    	document.getElementById("b").value = "CRISIS";
			}
		}
		
}