package tp1_1;

import java.math.BigDecimal;

/**
 * 
 * @author Thomas Ccottin
 * 
 * Represents a point in a plan. Coordinates are double values.
 *
 */
public class Point {
	
	/*
	 * Static final because the same for all the Point objects and not updatable.
	 */
	public static final double EPSILON = 0.0001;
	
	private char id;
	private BigDecimal x,y;
	
	/**
	 * Constructor
	 * @param id Name of the point
	 * @param x Abscissa
	 * @param y Ordinates 
	 */
	public Point(char id, double x, double y){
		this.id = id;
		this.x = new BigDecimal(x);
		this.y = new BigDecimal(y);
	}
	
	/**
	 * Printing method
	 * Needs to be public in order to be accessed by the outside, and not static because refers to an object
	 */
	public void affiche(){
		StringBuffer res = new StringBuffer("Point ");
		res.append(this.id);
		res.append(", abs=");
		res.append(this.x);
		res.append(" ord=");
		res.append(this.y);
		System.out.println(res.toString());
	}
	
	/*
	 * toString sends the output back, while affiche prints it 
	 */
	
	/**
	 * Translates x and y
	 * @param tx Abscissa translation
	 * @param ty Ordinate translation
	 */
	public boolean translate(double tx, double ty){
		if(tx==Double.POSITIVE_INFINITY || tx==Double.NEGATIVE_INFINITY || tx==Double.NaN)
			return false;
		if(ty==Double.POSITIVE_INFINITY || ty==Double.NEGATIVE_INFINITY || ty==Double.NaN)
			return false;
		this.x.add(new BigDecimal(tx));
		this.y.add(new BigDecimal(ty));
		return true;
	}
	
	/*
	 * In order to translate A to B, we need to call translate with tx = a.getX()-b.getX() and so as ty
	 */
	
	/**
	 * Returns the distance between the point and another one
	 * @param p2 Other point
	 * @return double : distance
	 */
	public double distance(Point p2){
		BigDecimal a = p2.getX().subtract(this.getX()).pow(2);
		BigDecimal b = p2.getY().subtract(this.getY()).pow(2);
		return Math.sqrt(a.add(b).doubleValue());
	}
	
	/**
	 * Return whether two points are superposed or not
	 * @param p2 Other point
	 * @return boolean
	 */
	public boolean confondu(Point p2){
		/*
		if (p2.getX()!= this.getX())
			return false;
		if (p2.getY() != this.getY())
			return false;
		return true;
		*/
		if (this.distance(p2) <= EPSILON)
			return true;
		return false;
	}
	
	/**
	 * Getter x
	 * @return BigDecimal : abscissa
	 */
	public BigDecimal getX(){
		return x;
	}
	
	/**
	 * Getter y
	 * @return BigDecimal: ordinate
	 */
	public BigDecimal getY(){
		return y;
	}
	

}
