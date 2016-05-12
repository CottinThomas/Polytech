package exercice1;
/**
 * Exceptions for TODOList: bad commands management
 * @author Thomas COTTIN
 */
@SuppressWarnings("serial")
public class TODOListSaisirException extends Exception{
	
	private String command;
	
	public TODOListSaisirException(String command){
		super();
		this.command = command;
	}

	public String toString(){
		StringBuilder sb = new StringBuilder();
		sb.append(super.toString()).append("\n");
		sb.append("Tried to perform the following command: \t"+command).append("\n");
		sb.append("Correct commands are : \n");
		sb.append("- add [your task] \t adds the task to the list\n");
		sb.append("- list \t\t\t lists the advailable tasks\n");
		sb.append("- first \t\t starts the first task (prints it and removes it form the list)\n");
		sb.append("- last \t\t\t starts the last task (prints it and removes it form the list)\n");
		return sb.toString();
	}
	
}
