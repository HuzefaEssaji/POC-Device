function validation(){
	
	localStorage.setItem("Height", document.getElementById('Height').value);
	localStorage.setItem("Weight", document.getElementById('Weight').value);
	localStorage.setItem("Systolic", document.getElementById('Systolic').value);
	localStorage.setItem("Diastolic", document.getElementById('Diastolic').value);


if (document.getElementById('Age').value==""
                 || document.getElementById('Age').value==undefined)
                {
                    alert ("Please Enter Your Age");
                    
                }
else if (document.getElementById('Height').value==""
                 || document.getElementById('Height').value==undefined)
                {
                    alert ("Please Enter Your Height");
                    
                }
				
else if(!document.getElementById('1').checked && !document.getElementById('2').checked) {alert ("Please Enter Your Gender");}		
				
else if (document.getElementById('Weight').value==""
                 || document.getElementById('Weight').value==undefined)
                {
                    alert ("Please Enter Your Weight");
                    
                }
else if (document.getElementById('Systolic').value==""
                 || document.getElementById('Systolic').value==undefined)
                {
                    alert ("Please Enter Your Systolic Blood Pressure");
                    
                }
else if (document.getElementById('Diastolic').value==""
                 || document.getElementById('Diastolic').value==undefined)
                {
                    alert ("Please Enter Your Diastolic Blood Pressure");
                    
                }				

else{location.href = 'next.html';}			

				
}
