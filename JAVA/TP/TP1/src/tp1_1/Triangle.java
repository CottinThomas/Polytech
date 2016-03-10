package tp1_1;

public class Triangle {
	
	private Point pointA, pointB, pointC;
	
	public Triangle(Point pointA, Point pointB, Point pointC){
		this.pointA = pointA;
		this.pointB = pointB;
		this.pointC = pointC;
	}
	
	public boolean confondu(Triangle t){
		if(this.pointA.confondu(t.pointA)){
			if(this.pointB.confondu(t.pointB)){
				if(this.pointC.confondu(t.pointC))
					return true;
			}else if(this.pointB.confondu(t.pointC)){
				if(this.pointC.confondu(t.pointB))
					return true;
			}
		}
		else if(this.pointA.confondu(t.pointB)){
			if(this.pointB.confondu(t.pointC)){
				if(this.pointC.confondu(t.pointA))
					return true;
			}else if(this.pointB.confondu(t.pointA)){
				if(this.pointC.confondu(t.pointC))
					return true;
			}
		}
		else if(this.pointA.confondu(t.pointC)){
			if(this.pointB.confondu(t.pointA)){
				if(this.pointC.confondu(t.pointB))
					return true;
			}else if(this.pointB.confondu(t.pointB)){
				if(this.pointC.confondu(t.pointA))
					return true;
			}
		}
		return false;
	}


}
