package com.zhb.demo;

import java.util.List;

import org.springframework.stereotype.Controller;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.ui.Model;

@Controller
public class HelloController {

	private final UserRepository userRepository;

	public HelloController(UserRepository userRepository) {
		this.userRepository = userRepository;
	}

	@GetMapping("/")
	@ResponseBody
	@Transactional(readOnly = true)
	/*public List<User> users(@RequestParam String name) {
		return this.userRepository.findByName(name);
	}*/
	public String users(@RequestParam String name, Model model) {
		model.addAttribute(this.userRepository.findByName(name));

		return "/";
	}

}
