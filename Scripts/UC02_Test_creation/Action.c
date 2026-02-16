Action()
{
	
	srand(time(NULL));
//	usersPerStep = rand()%1 + 1;
	usersPerStep = atoi(lr_eval_string("{vu_per_step}"));
//	rampUpMs = (rand()%1 + 1) * 60000;
	rampUpMs = 0;
	rampDownMs = 0;
//	stepLengthMs = (rand()%1 + 1) * 60000;
	stepLengthMs = atoi(lr_eval_string("{step_len}")) * 60000;
//	stepCount = rand()%2 + 1
	stepCount = atoi(lr_eval_string("{step_count}"));
	durationMs = 8000;
	durationAddedOnLastStepMs = atoi(lr_eval_string("{durationAddedOnLastStep}")) * 60000;
//	totalDuration = (stepCount * (stepLengthMs + rampUpMs) + rampDownMs) / 1000;
	totalDuration = (stepCount * (stepLengthMs + rampUpMs) + rampDownMs + durationAddedOnLastStepMs) / 1000;
	sprintf(body,
    "{"
    "\"comment\":\"\","
    "\"contentFormat\":\"yaml\","
    "\"contentModelVersion\":\"2.0.0\","
    "\"labelSet\":[],"
    "\"requestCount\":1,"
    "\"testType\":\"%s\","
    "\"projectName\":\"mock_%s\","
    "\"contentV2\":{\"boomqTestPlan\":{\"threadGroups\":[{\"boomqConfiguration\":{\"resourceConfiguration\":{\"testRunnerIds\": [2]},\"loadProfilePercent\":100},\"enabled\":true,\"id\":\"e0b7a707-7c7e-4e80-a48b-3df6adb314d4\",\"label\":\"New group 1\",\"steps\":[],\"type\":\"BOOMQ_STABLE_SCALABILITY\",\"typeDisplayName\":\"\",\""
    "threadGroupElements\":[{\"children\":[{\"children\":\"\",\"individualProperties\":{\"useKeepAlive\":true,\"type\":\"HTTP\",\"retrieveAllEmbeddedResources\":true,\"followRedirects\":true,\"automaticallyRedirect\":false,\"method\":\"POST\",\"browserCompatibleHeaders\":false,\"doMultipartPost\":false,\"path\":\"/info/postBalances\",\"port\":\"43080\",\"protocol\":\"http\",\"search\":\"?\",\"serverName\":\"82.142.167.46\",\"headers\":{\"Content-Type\":\"application/json\"},\"queryParameters\":[]," 
    "\"body\":\"{\\n\\t\\\"rqUID\\\": \\\"58dgtf565j8547f64ke7\\\",\\n\\t\\\"clientId\\\": \\\"1050000000000000000\\\",\\n\\t\\\"account\\\": \\\"30500000000000000001\\\",\\n\\t\\\"openDate\\\": \\\"2020-01-01\\\",\\n\\t\\\"closeDate\\\": \\\"2025-01-01\\\"\\n}\",\"bodyParameters\":[]},\"timerList\":[],\"label\":\"mock\",\"id\":\"f1ec7282-7943-4b67-b370-2a8a3db4c9ad\",\"type\":\"SAMPLER\",\"enabled\":true,\"assertions\":[{\"applyTo\":\"PARENT\",\"condition\":\"EQUALS\",\"or\":false,\"values\":[\"200\"]," 
    "\"label\":\"boomq_assertion_caaad1c8-f936-48e6-b240-5e0f1df8bea8\",\"id\":\"caaad1c8-f936-48e6-b240-5e0f1df8bea8\",\"type\":\"RESPONSE_CODE\",\"ignoreStatus\":false,\"enabled\":true,\"typeDisplayName\":\"\"}],\"extractors\":[],\"typeDisplayName\":\"HTTP Request\"}],"
    "\"individualProperties\":{\"includeDurationOfAllElementsToGeneratedSampler\":false,\"generateParentSampler\":false,\"type\":\"TRANSACTION\"},\"timerList\":[],\"label\":\"Transaction 1\",\"id\":\"4cfc4817-883f-4195-ab96-f745232202f2\",\"type\":\"CONTROLLER\",\"enabled\":true,\"creationIndex\":1,\"typeDisplayName\":\""
    "Transaction Controller\"}]}],\"runThreadGroupConsecutively\":false,\"loadProfileType\":\"PER_TEST\",\"functionalMode\":false,\"runTearDownAfterShutdown\":true,\"configurationElements\":[{\"clearControlledByThreadGroup\":false,\"cookiePolicy\":\"STANDARD\",\"clearEachIteration\":false,\"userDefinedCookies\":[],\"label\":\"Http cookie manager\",\"id\":\"267772a2-62f5-410a-954e-8fd3874a8c8a\",\"type\":\"HTTP_COOKIE_MANAGER\",\"enabled\":true},{\"headers\":{\"User-Agent\":\"Mozilla/5.0\"},\"label\":\""
    "Http header manager\",\"id\":\"fdf1d819-5477-4440-8f26-17846efd01b6\",\"type\":\"HTTP_HEADER_MANAGER\",\"enabled\":true},{\"label\":\"Http request defaults\",\"type\":\"HTTP_REQUEST_DEFAULTS\",\"enabled\":true,\"id\":\"46efd3f9-41e3-4f24-97da-608fb4d823de\",\"connectTimeout\":60000,\"responseTimeout\":120000}],\"loadProfile\":{\"usersPerStep\":%d,\"rampDownMs\":%d,\"durationAddedOnLastStepMs\":%d,\"boomqProfileType\":\"%s\",\"rampUpMs\":%d,\"stepLengthMs\":%d,\"stepCount\":%d},\"timers"
    "\":[{\"timerType\":\"CONSTANT\",\"label\":\"boomq_timer_222f108a-2342-44b6-b9f0-62ebfdb5edcd\",\"id\":\"222f108a-2342-44b6-b9f0-62ebfdb5edcd\",\"durationMs\":%d,\"enabled\":true}]},\"slaGroupList\":[],\"supportingFiles\":[],\"supportingFilesV2\":[]},\"totalDuration\":%d"
    "}",
    lr_eval_string("{testType}"),
    lr_eval_string("{Date}"),
//    usersPerStep,
	atoi(lr_eval_string("{vu_per_step}")),
    rampDownMs,
    durationAddedOnLastStepMs,
    lr_eval_string("{testType}"),
    rampUpMs,
    stepLengthMs,
    stepCount,
    durationMs,
    totalDuration
	);
    
//    lr_save_int(usersPerStep, "usersPerStep");
//    lr_save_int(rampUpMs, "rampUpMs");
//    lr_save_int(stepLengthMs, "stepLengthMs");
//    lr_save_int(stepCount, "stepCount");
//    lr_save_int(rampDownMs, "rampDownMs");
//    lr_save_int(durationMs, "durationMs");
//    lr_save_int(totalDuration, "totalDuration");
    lr_save_string(body, "request_body");
    
    web_set_sockets_option("SSL_VERSION", "AUTO");
    web_set_max_html_param_len("2000"); 
    
	lr_start_transaction("UC_02_TR_01_login");

	
	web_add_header("Origin", 
		"https://dev-boomq.pflb.ru");

	web_add_auto_header("Sec-Fetch-Dest", 
		"empty");

	web_add_auto_header("Sec-Fetch-Mode", 
		"cors");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_header("X-Client-Date", 
		"2026-02-01T21:24:31.688Z");

	web_add_auto_header("sec-ch-ua", 
		"\"Not(A:Brand\";v=\"8\", \"Chromium\";v=\"144\", \"Microsoft Edge\";v=\"144\"");

	web_add_auto_header("sec-ch-ua-mobile", 
		"?0");

	web_add_auto_header("sec-ch-ua-platform", 
		"\"Windows\"");

	lr_think_time(12);
	
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
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		ITEMDATA, 
//		"Name=username", "Value=admin_gr3@mail.com", ENDITEM, 
//		"Name=password", "Value=Wsx321!@#", ENDITEM, 
		"Name=username", "Value={login}", ENDITEM,
		"Name=password", "Value={password}", ENDITEM,
		"Name=submit", "Value=Login", ENDITEM, 
		LAST);
	
	lr_output_message("Токен 1 (длина=%d): %s", strlen(lr_eval_string("{token}")), lr_eval_string("{token}"));

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
	
	web_url("user", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/user", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t5.inf", 
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
		"Snapshot=t6.inf", 
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
		"Snapshot=t7.inf", 
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
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);

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
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_output_message("Токен 2 (длина=%d): %s", strlen(lr_eval_string("{token_2}")), lr_eval_string("{token_2}"));

	web_add_auto_header(
		"Authorization",
		"Bearer {token_2}");
	
	web_url("testRunner", 
		"URL=https://dev-boomq.pflb.ru/test-runner-srv/testRunner?sort=id,desc", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);

	
	lr_end_transaction("UC_02_TR_01_login",LR_AUTO);
	

	lr_start_transaction("UC_02_TR_02_go_to_tests");
	

	web_add_auto_header("Sec-Fetch-Dest", 
		"empty");

	web_add_auto_header("Sec-Fetch-Mode", 
		"cors");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_auto_header("sec-ch-ua", 
		"\"Not(A:Brand\";v=\"8\", \"Chromium\";v=\"144\", \"Microsoft Edge\";v=\"144\"");

	web_add_auto_header("sec-ch-ua-mobile", 
		"?0");

	web_add_auto_header("sec-ch-ua-platform", 
		"\"Windows\"");

	lr_think_time(3);

	web_add_auto_header(
		"Authorization",
		"Bearer {token_2}");
	
	web_url("label", 
		"URL=https://dev-boomq.pflb.ru/project-srv/project/label?query=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/tests", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);

	web_add_auto_header(
		"Authorization",
		"Bearer {token_2}");
	
	web_url("project", 
		"URL=https://dev-boomq.pflb.ru/project-srv/project?sort=lastModified,desc&page=0&size=9", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/tests", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		LAST);

	
	lr_end_transaction("UC_02_TR_02_go_to_tests",LR_AUTO);

	
	lr_start_transaction("UC_02_TR_03_test_create");


	web_add_header("Origin", 
		"https://dev-boomq.pflb.ru");

	web_add_auto_header(
		"Authorization",
		"Bearer {token_2}");

		web_custom_request("project_2", 
		"URL=https://dev-boomq.pflb.ru/project-srv/project", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={request_body}", 
		EXTRARES, 
		"Url=../static/media/check.9725c0396328bae9471b624111fc14ca.svg", "Referer=https://dev-boomq.pflb.ru/account/new-test", ENDITEM, 
		LAST);
	
	
	lr_end_transaction("UC_02_TR_03_test_create",LR_AUTO);

	return 0;
}