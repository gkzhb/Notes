package com.zhb.demo;

import java.util.List;

import org.springframework.data.jdbc.repository.query.Query;
import org.springframework.data.repository.CrudRepository;
import org.springframework.data.repository.query.Param;

interface UserRepository extends CrudRepository<User, Long> {

	@Query("select id, user_name, date_of_birth from user where upper(user_name) like '%' || upper(:name) || '%' ")
	List<User> findByName(@Param("name") String name);

}
