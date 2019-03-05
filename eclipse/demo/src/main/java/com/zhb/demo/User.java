package com.zhb.demo;

import java.time.LocalDate;

import org.springframework.data.annotation.Id;

class User {

	@Id
	private Long id;

	private String userName;

	private LocalDate dateOfBirth;

	public Long getId() {
		return this.id;
	}

	public void setId(Long id) {
		this.id = id;
	}

	public String getUserName() {
		return this.userName;
	}

	public void setUserName(String userName) {
		this.userName = userName;
	}

	public LocalDate getDateOfBirth() {
		return this.dateOfBirth;
	}

	public void setDateOfBirth(LocalDate dateOfBirth) {
		this.dateOfBirth = dateOfBirth;
	}

}
