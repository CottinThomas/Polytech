package exercice1;

public class Robot {
	private Outil[] cases;
	private int position;

	public Robot(int k) {
		this.cases = new Outil[k];

		for (int i = 0; i < k; i++) {
			this.cases[i] = null;
		}
	}

	public boolean caseCouranteVide() {
		return this.cases[this.position] == null;
	}

	public Outil retire() throws CaseException {
		if (this.caseCouranteVide())
			throw new CaseException("case vide ! ", this.cases, this.position,
					null);

		return this.cases[this.position] = null;
	}

	public void ajoute(Outil e) throws CaseException {
		if (!this.caseCouranteVide())
			throw new CaseException("Case non vide ! ", this.cases,
					this.position, e);

		this.cases[this.position] = e;
	}

	public void deplaceBras(int i) throws DeplacementException {
		if (i < 0 || i >= this.cases.length)
			throw new DeplacementException(
					"impossible de mettre le bras en position ", i);

		this.position = i;
	}

	public String toString() {
		String s = "\nbras en position " + this.position + "\n";

		for (int i = 0; i < this.cases.length; i++) {
			s = s + "position " + i + " : " + this.cases[i] + "\n";
		}

		return s;
	}

}
