package exercice1;
import java.util.LinkedList;
import java.util.Scanner;

/**
 * TODOList: you can manage some tasks using basic commands (console project)
 * @author Thomas COTTIN
 */
public class TODOList {
	
	// Used for messages display
	private static final String EMPTY_MESSAGE = "No task available.\n";
	private static final String SELECTED_TASK_INTRO = "Your new task: ";
	
	// Storage of the tasks
	private LinkedList<String> toDoList;
	
	public TODOList(){
		this.toDoList = new LinkedList<String>();
	}
	
	// Manage an incoming command, returns whether or not it has been treated.
	private boolean perfomCommand(String command) throws TODOListSaisirException{
		String [] params = command.split("\\s");
		if(params.length == 1){
			switch(params[0]){
				case "list":
					System.out.println(this);
					break;
				case "first":
					if(toDoList.isEmpty())
						System.out.println(EMPTY_MESSAGE);
					else
						System.out.println(SELECTED_TASK_INTRO + toDoList.removeFirst());
					break;
				case "last":
					if(toDoList.isEmpty())
						System.out.println(EMPTY_MESSAGE);
					else
						System.out.println(SELECTED_TASK_INTRO + toDoList.removeLast());
					break;
				default:
					throw new TODOListSaisirException(command);
			}
			return true;
		}
		if(params.length==2){
			if(params[0].equals("add"))
				return toDoList.add(todoBuilder(params));
		}
		throw new TODOListSaisirException(command);
		
	}
	
	// Extracts the task from the splited command
	private String todoBuilder(String[] addparams){
		if(addparams.length < 2)
			return null;
		StringBuilder todo = new StringBuilder();
		for(int i = 1; i < addparams.length-1; i++){
			todo.append(addparams[i]).append(" ");
		}
		todo.append(addparams[addparams.length-1]);
		return todo.toString();
	}
	
	/**
	 * Run the task management system.
	 */
	public void run(){
		boolean next = true;
		Scanner s = new Scanner(System.in);
		while(next){
			System.out.println("Type a new command:");
			String command = s.nextLine();
			try{
				next = perfomCommand(command);
			}catch(TODOListSaisirException e){
				System.out.println(e);
			}
		}
		s.close();
		System.out.println("Terminated");
	}
	
	/**
	 * Return a formated string representing the tasks list.
	 */
	public String toString(){
		StringBuilder sb = new StringBuilder();
		if(toDoList.size() > 0){
			sb.append("Tasks list:");
			for(String task : toDoList){
				sb.append("\n").append("- ").append(task);
			}
		}
		else
			sb.append(EMPTY_MESSAGE);
		return sb.toString();
	}
	
	
	public static void main(String[] args) {
		TODOList toDoList = new TODOList();
		toDoList.run();
	}
}
