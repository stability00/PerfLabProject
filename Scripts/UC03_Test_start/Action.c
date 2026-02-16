Action()
{

	web_set_sockets_option("SSL_VERSION", "AUTO");
    web_set_max_html_param_len("2000"); 
	
	lr_start_transaction("login");


	web_add_header("Origin", 
		"https://dev-boomq.pflb.ru");

	web_add_auto_header("Sec-Fetch-Dest", 
		"empty");

	web_add_auto_header("Sec-Fetch-Mode", 
		"cors");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_header("X-Client-Date", 
		"2026-02-03T21:55:38.559Z");

	lr_think_time(11);
	
	web_reg_save_param("token",
		"LB=authorization: ",
		"RB=\r\n",
		"Search=Headers",
		LAST);
	
	web_submit_data("login", 
		"Action=https://dev-boomq.pflb.ru/auth-srv/login", 
		"Method=POST", 
		"EncType=multipart/form-data", 
		"TargetFrame=", 
		"Referer=https://dev-boomq.pflb.ru/authorize", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=username", "Value={login}", ENDITEM, 
		"Name=password", "Value={password}", ENDITEM, 
		"Name=submit", "Value=Login", ENDITEM, 
		LAST);

	web_add_auto_header(
		"Authorization",
		"Bearer {token}");
	
	web_url("user", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/user", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	web_add_auto_header(
		"Authorization",
		"Bearer {token}");
	
	web_url("config.json", 
		"URL=https://dev-boomq.pflb.ru/config.json", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

	web_add_auto_header(
		"Authorization",
		"Bearer {token}");
	
	web_url("modelSchema", 
		"URL=https://dev-boomq.pflb.ru/project-srv/modelSchema", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=../static/media/en.b1acfc6b06bfe6e29bfbfc06d09d8177.svg", "Referer=https://dev-boomq.pflb.ru/account/new-test", ENDITEM, 
		LAST);

	web_add_auto_header(
		"Authorization",
		"Bearer {token}");
	
	web_url("identityProvider", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/identityProvider", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);

	web_add_auto_header(
		"Authorization",
		"Bearer {token}");
	
	web_url("team", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/team?size=2", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);

	web_add_auto_header(
		"Authorization",
		"Bearer {token}");
	
	web_add_auto_header(
		"Authorization",
		"Bearer {token}");

	web_reg_save_param("token_2",
		"LB=authorization: ",
		"RB=\r\n",
		"Search=Headers",
		LAST);
	
	web_url("teamContext", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/teamMember/teamContext?teamId=22", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);

	web_add_auto_header(
		"Authorization",
		"Bearer {token_2}");

	web_url("testRunner", 
		"URL=https://dev-boomq.pflb.ru/test-runner-srv/testRunner?sort=id,desc", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("Origin", 
		"https://dev-boomq.pflb.ru");

	web_add_auto_header(
		"Authorization",
		"Bearer {token_2}");
		
	web_add_header("Content-Type", "application/json");

	sprintf(body_user_2_str,
	"{\"email\":\"%s\",\"id\":1925,\"language\":\"EN\",\"notificationEnabled\":false}",        	
    lr_eval_string("{login}")
	);
	
	lr_save_string(body_user_2_str, "body_user_2");
	
	web_custom_request("user_2", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/user", 
		"Method=PUT", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		"Body={body_user_2}", 
		LAST);

	web_add_auto_header(
		"Authorization",
		"Bearer {token_2}");

	web_url("22", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/team/22", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);
	

	lr_end_transaction("login",LR_AUTO);

	
	lr_think_time(8);

	
	lr_start_transaction("tests_open");
	

	web_add_auto_header(
		"Authorization",
		"Bearer {token_2}");
	
	web_url("label", 
		"URL=https://dev-boomq.pflb.ru/project-srv/project/label?query=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/tests", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		LAST);

	web_add_auto_header(
		"Authorization",
		"Bearer {token_2}");
	
	web_reg_save_param_json(
		"ParamName=t_id",
		"QueryString=$.content[*].id",
		SEARCH_FILTERS,
		"Scope=BODY",
		LAST);
	
	web_url("project", 
		"URL=https://dev-boomq.pflb.ru/project-srv/project?sort=lastModified,desc&page=0&size=9", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/tests", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		LAST);

	
	lr_end_transaction("tests_open",LR_AUTO);

	
	lr_start_transaction("test_select");

	
	web_add_auto_header(
		"Authorization",
		"Bearer {token_2}");
	
	web_reg_save_param_json(
		"ParamName=v_id",
		"QueryString=$version[*].id",
		SEARCH_FILTERS,
		"Scope=BODY",
		LAST);
	
	web_url("2699", 
		"URL=https://dev-boomq.pflb.ru/project-srv/project/{t_id}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/tests/{t_id}", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		LAST);

	web_add_auto_header(
		"Authorization",
		"Bearer {token_2}");
	
	web_url("3931", 
		"URL=https://dev-boomq.pflb.ru/project-srv/project/{t_id}/version/{v_id}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/tests/{t_id}", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		LAST);

	web_add_auto_header(
		"Authorization",
		"Bearer {token_2}");
	
	web_url("downloadLink", 
		"URL=https://dev-boomq.pflb.ru/project-srv/project/{t_id}/version/{v_id}/downloadLink", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/tests/{t_id}", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/minio/boomq/boomq/teams/22/projects/{t_id}/v_{v_id}.yaml?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIAIOSFODNN7EXAMPLE/20260203/us-east-1/s3/aws4_request&X-Amz-Date=20260203T215633Z&X-Amz-Expires=604800&X-Amz-SignedHeaders=host&X-Amz-Signature=32c670d0449dd15d97aac0504ae903a9bd6ea8f48d7b99050e2f7eecb091c77c", "Referer=https://dev-boomq.pflb.ru/account/tests/{t_id}", ENDITEM, 
		LAST);

	
	lr_end_transaction("test_select",LR_AUTO);

	
	lr_start_transaction("test_run");

	
	web_add_header("Origin", 
		"https://dev-boomq.pflb.ru");

	lr_think_time(4);
	
	sprintf(body_test_str,
	"{" 
	"\"comment\":\"\",\"labelSet\":[],\"projectId\":\"%s\",\"projectVersionId\":%s,\"testMode\":\"TEST\",\"testProjectId\":\"%s\",\"testProjectVersionId\":%s}",        	
    lr_eval_string("{t_id}"),
    lr_eval_string("{v_id}"),
    lr_eval_string("{t_id}"),
    lr_eval_string("{v_id}")
	);
	
	lr_save_string(body_test_str, "body_test");

	web_add_auto_header(
		"Authorization",
		"Bearer {token_2}");
	
	
	web_custom_request("test", 
		"URL=https://dev-boomq.pflb.ru/test-srv/test", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/tests/{t_id}", 
		"Snapshot=t17.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={body_test}", 
		LAST);

	web_add_auto_header(
		"Authorization",
		"Bearer {token_2}");
	
	web_url("project_2", 
		"URL=https://dev-boomq.pflb.ru/project-srv/project?sort=lastModified,desc&size=999", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/test-runs", 
		"Snapshot=t18.inf", 
		"Mode=HTML", 
		LAST);

	web_add_auto_header(
		"Authorization",
		"Bearer {token_2}");
	
	web_url("label_2", 
		"URL=https://dev-boomq.pflb.ru/test-srv/test/label?query=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/test-runs", 
		"Snapshot=t19.inf", 
		"Mode=HTML", 
		LAST);

	web_add_auto_header(
		"Authorization",
		"Bearer {token_2}");
	
	web_url("user_3", 
		"URL=https://dev-boomq.pflb.ru/test-srv/user", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/test-runs", 
		"Snapshot=t20.inf", 
		"Mode=HTML", 
		LAST);

	web_add_auto_header(
		"Authorization",
		"Bearer {token_2}");
	
	web_url("test_2", 
		"URL=https://dev-boomq.pflb.ru/test-srv/test?sort=createDate,desc&displayState=INITIALIZATION,WAITING,RUNNING,TEST_STOPPING", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/test-runs", 
		"Snapshot=t21.inf", 
		"Mode=HTML", 
		LAST);

	web_add_auto_header(
		"Authorization",
		"Bearer {token_2}");
	
	web_url("test_3", 
		"URL=https://dev-boomq.pflb.ru/test-srv/test?sort=createDate,desc&page=0&size=7", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/test-runs", 
		"Snapshot=t22.inf", 
		"Mode=HTML", 
		LAST);

	
	lr_end_transaction("test_run",LR_AUTO);


	return 0;
}