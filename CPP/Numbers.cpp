/*




*/




/* Precision: default, fixed, scientific */
#include <iomanip>
  double a = 3.1415926534;
  double b = 2006.0;
  double c = 1.0e-10;
  
    cout.precision(5); 

  cout << "default:\n"; // 5 including integer digits before decimal point
  cout << a << '\n' << b << '\n' << c << '\n';

  cout << '\n';

  cout << "fixed:\n" << fixed; // 5 NOT including integer digits before decimal point. It puts zeros if required
  cout << a << '\n' << b << '\n' << c << '\n';
//NOTE: fixed should not be declared as any variable, else it will override it
  cout << '\n';

  cout << "scientific:\n" << std::scientific; //Gives in 'e' format
  cout << a << '\n' << b << '\n' << c << '\n';

//If you again want in, say, fixed format. you must manipulate cout with fixed by cout<<fixed<<....;








