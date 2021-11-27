#ifndef RECT_H
#define RECT_H

class Rectangle {
   private:
      double length;
      double width;
      
   public:
      Rectangle();                                                                           
      Rectangle(double , double );   
      void setLength(double );                 
      void setWidth(double );                  
      double getLength(); 
      double getWidth();
      //Add necessary operators
      //copy constructor;
      //Rectangle(Rectangle &copy);
      //overloading operators
      Rectangle& operator=(const Rectangle &otherRect);
      const Rectangle operator +(const Rectangle &otherRect) const;
      const Rectangle operator -(const Rectangle &otherRect) const;
      bool operator ==(const Rectangle &otherRect) const;
      bool operator !=(const Rectangle &otherRect) const;
      bool operator >(const Rectangle &otherRect) const;

      //friend functions have access to private and protected variables
      //friend functions do not require the :: operator
      friend std::ostream& operator<<(std::ostream&, const Rectangle&);
      friend std::istream& operator>>(std::istream& isObject,  Rectangle&);
};

#endif