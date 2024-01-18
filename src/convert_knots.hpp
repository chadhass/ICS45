double knots_to_miles_per_minute(int knots)
{
double ktofeetph = 6076; 
double convrate = 1/5280; 
double mph = 60; 

double cmph = knots * ktofeetph * convrate; 
double cmpm = cmph / mph; 

return cmpm;
}
