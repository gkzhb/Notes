import java.util.regex.*;

public class HelloWorld {
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//System.out.println("Hello World!");
		String target="<input type=\"hidden\" name=\"lt\" value=\"LT-1316093-wJydaIE4fm1efQ7EKj9w3cOFB9W5zi1529506925448-0Mtw-cas\">\n";
		String regex="name=\"lt\" value=\"LT-[A-Za-z0-9-]*\"";
		Pattern p=Pattern.compile(regex);
		Matcher m=p.matcher(target);
		//boolean flag=target.matches(regex);
		boolean b=m.find();
		String res=m.group();
		System.out.println(b);
		System.out.println(res);
		res=res.substring(res.indexOf("value=\"")+7,res.lastIndexOf("\""));
		
		System.out.println(res);
		/*if (flag)
			System.out.println(target+"... is ok");
		else
			System.out.println(target+"... no");
		*/
	}

}
