Action()
{
	int i, count;
	char paramName[100];
	int reportFound = 0;
	
	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_add_header("Sec-Fetch-Site", 
		"none");

	web_add_header("Sec-Fetch-Mode", 
		"no-cors");

	web_add_auto_header("Sec-Fetch-Dest", 
		"empty");

	web_url("manifest.json", 
		"URL=https://dev-boomq.pflb.ru/manifest.json", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	lr_start_transaction("UC_04_TR_01_Login");

	web_add_header("Origin", 
		"https://dev-boomq.pflb.ru");

	web_add_auto_header("Sec-Fetch-Mode", 
		"cors");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_header("X-Client-Date", 
		"2026-02-02T07:42:04.146Z");

	web_add_auto_header("sec-ch-ua", 
		"\"Chromium\";v=\"142\", \"YaBrowser\";v=\"25.12\", \"Not_A Brand\";v=\"99\", \"Yowser\";v=\"2.5\"");

	web_add_auto_header("sec-ch-ua-mobile", 
		"?0");

	web_add_auto_header("sec-ch-ua-platform", 
		"\"Windows\"");

	lr_think_time(30);
	

	// 1. Параметризация логина и пароля (если нужно)
    //lr_save_string("admin_gr3@mail.com", "username");
    //lr_save_string("Wsx321!@#", "password");
    
    // 2. Регистрируем правило корреляции ДО запроса
    web_set_max_html_param_len("5000");   
    web_reg_save_param("AuthToken",
        "LB=set-cookie: boomq_auth=",
        "RB=;",
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
		"Name=username", "Value={user_login}", ENDITEM, 
        "Name=password", "Value={user_pass}", ENDITEM, 
        "Name=submit", "Value=Login", ENDITEM, 
		LAST);
	
    
    // 4. Проверяем, что токен получен
    if (strlen(lr_eval_string("{AuthToken}")) > 0) {
        lr_output_message("Токен получен: %s", lr_eval_string("{AuthToken}"));
        lr_save_string(lr_eval_string("Bearer {AuthToken}"), "BearerToken");
		web_add_auto_header("Authorization", lr_eval_string("{BearerToken}"));
    } else {
        lr_error_message("Токен не получен!");
        return -1;
    }


	web_url("user", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/user", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	web_url("identityProvider", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/identityProvider", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

	web_url("22", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/team/22", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);
    
    web_set_max_html_param_len("5000");   
    web_reg_save_param("NewAuthToken",
        "LB=set-cookie: boomq_auth=",
        "RB=\n",
        LAST);
    
	web_url("teamContext", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/teamMember/teamContext?teamId=22", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);
    
    if (strlen(lr_eval_string("{NewAuthToken}")) > 0) {
        lr_output_message("Токен получен: %s", lr_eval_string("{NewAuthToken}"));
        lr_save_string(lr_eval_string("Bearer {NewAuthToken}"), "BearerToken");
		web_add_auto_header("Authorization", lr_eval_string("{BearerToken}"));
    } else {
        lr_error_message("Токен не получен!");
        return -1;
    }

	
	
	web_url("testRunner", 
		"URL=https://dev-boomq.pflb.ru/test-runner-srv/testRunner?sort=id,desc", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);

	web_url("modelSchema", 
		"URL=https://dev-boomq.pflb.ru/project-srv/modelSchema", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC_04_TR_01_Login",LR_AUTO);

	lr_start_transaction("UC_04_TR_02_OpenReports");

	web_add_header("Origin", 
		"https://dev-boomq.pflb.ru");

	lr_think_time(9);

	web_add_header("Content-Type", "application/json");
	web_custom_request("search", 
		"URL=https://dev-boomq.pflb.ru/report-srv/report/search", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/reports", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		"Body={\"pagination\":{\"pageNumber\":0,\"pageSize\":9},\"sort\":[{\"field\":\"CREATED_AT\",\"direction\":\"DESC\"}]}", 
		LAST);

	lr_end_transaction("UC_04_TR_02_OpenReports",LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("UC_04_TR_03_CreateNewReport");

	web_url("test", 
		"URL=https://dev-boomq.pflb.ru/test-srv/test?sort=createDate,desc&displayState=FINISHED", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/reports/new", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC_04_TR_03_CreateNewReport",LR_AUTO);

	lr_start_transaction("UC_04_TR_04_CreateContentReport");

	web_add_header("Origin", 
		"https://dev-boomq.pflb.ru");

	lr_think_time(8);

	
	
	//ПАРАМЕТРИЗАЦИЯ ДАННЫХ ОТЧЕТА

	lr_save_string(lr_eval_string("TestReport_{report_id}{random_report_data_1}"), "ReportName");
	
	lr_save_string(lr_eval_string("Data_{random_report_data_1}"), "TableCell1");
	lr_save_string(lr_eval_string("Info_{random_report_data_2}"), "TableCell2");
	lr_save_string(lr_eval_string("Value_{random_report_data_3}"), "TableCell3");
	lr_save_string(lr_eval_string("Result_{random_report_data_1}"), "TableCell4");
	
	lr_save_string(lr_eval_string("TestText_{random_report_data_2}_RandomContentForLoadRunnerReport"), "ParagraphText");
	
	lr_save_string(lr_eval_string("ListElement_{random_report_data_3}"), "ListItem1");
	lr_save_string(lr_eval_string("Item_{random_report_data_1}"), "ListItem2");
	
	lr_save_string(lr_eval_string("ID_{report_id}"), "TableId");
	lr_save_string(lr_eval_string("ID_{report_id}"), "ParagraphId");
	lr_save_string(lr_eval_string("ID_{report_id}"), "ListId");
	

	web_reg_save_param_json(
	    "ParamName=report_id",
	    "QueryString=$.id",
	    SEARCH_FILTERS,
	    LAST);
	
	web_add_header("Content-Type", "application/json");
	web_custom_request("report", 
		"URL=https://dev-boomq.pflb.ru/report-srv/report", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/reports/new", 
		"Snapshot=t11.inf", 
		"Mode=HTML",  
		"Body={\"labelSet\":[],\"name\":\"{ReportName}\",\"testIdSet\":[],\"reportContent\":{\"charts\":[],\"reportMarkup\":\"[{\\\"id\\\":\\\"{TableId}\\\",\\\"type\\\":\\\"table\\\",\\\"data\\\":{\\\"withHeadings\\\":false,\\\"content\\\":[[\\\"{TableCell1}\\\",\\\"{TableCell2}\\\",\\\"{TableCell3}\\\",\\\"{TableCell4}\\\",\\\"\\\"],[\\\"{TableCell1}\\\",\\\"{TableCell2}\\\",\\\"{TableCell3}\\\",\\\"{TableCell4}\\\",\\\"\\\"],[\\\"{TableCell1}\\\",\\\"{TableCell2}\\\",\\\"{TableCell3}\\\",\\\"{TableCell4}\\\",\\\"\\\"],[\\\"{TableCell1}\\\",\\\"{TableCell2}\\\",\\\"{TableCell3}\\\",\\\"{TableCell4}\\\",\\\"\\\"],[\\\"{TableCell1}\\\",\\\"{TableCell2}\\\",\\\"{TableCell3}\\\",\\\"{TableCell4}\\\",\\\"\\\"]]}},{\\\"id\\\":\\\"{ListId}\\\",\\\"type\\\":\\\"list\\\",\\\"data\\\":{\\\"style\\\":\\\"unordered\\\",\\\"items\\\":[\\\"{ListItem1}\\\",\\\"{ListItem2}\\\"]}},{\\\"id\\\":\\\"{ParagraphId}\\\",\\\"type\\\":\\\"paragraph\\\",\\\"data\\\":{\\\"text\\\":\\\"{ParagraphText}\\\"}},{\\\"id\\\":\\\"Ao2kdtLsmR\\\",\\\"type\\\":\\\"image\\\",\\\"data\\\":{\\\"file\\\":{\\\"url\\\":\\\"data:image/png;base64,{image}\\\"},\\\"caption\\\":\\\"{random_report_data_2}\\\",\\\"withBorder\\\":false,\\\"stretched\\\":false,\\\"withBackground\\\":false}}]\",\"tables\":[]}}", 
		LAST);
	
	
	web_url("save_report", 
		"URL=https://dev-boomq.pflb.ru/report-srv/report/{report_id}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/reports/{report_id}", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		LAST);

	web_url("content_report", 
		"URL=https://dev-boomq.pflb.ru/report-srv/report/{report_id}/content", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/reports/{report_id}", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		LAST);

	web_url("test_2", 
		"URL=https://dev-boomq.pflb.ru/test-srv/test?sort=createDate,desc&displayState=FINISHED", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/reports/{report_id}", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC_04_TR_04_CreateContentReport",LR_AUTO);

	lr_start_transaction("UC_04_TR_05_CheckReport");

	web_add_header("Origin", 
		"https://dev-boomq.pflb.ru");

	lr_think_time(28);

	web_reg_save_param_json(
	    "ParamName=all_id_reports",
	    "QueryString=$.content[*].id",
	    "SelectAll=Yes",
	    SEARCH_FILTERS,
	    LAST);
	
	web_add_header("Content-Type", "application/json");
	web_custom_request("search_2", 
		"URL=https://dev-boomq.pflb.ru/report-srv/report/search", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/reports", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		"Body={\"pagination\":{\"pageNumber\":0,\"pageSize\":9},\"sort\":[{\"field\":\"CREATED_AT\",\"direction\":\"DESC\"}]}", 
		LAST);
	

	for (i = 1; i <= atoi(lr_eval_string("{all_id_reports_count}")); i++) {
	    sprintf(paramName, "{all_id_reports_%d}", i);
		    
	    lr_output_message("Элемент %d: OrderNumber = %s сравниваем с:%s", i, lr_eval_string(paramName), lr_eval_string("{report_id}"));
		    
	    if (strcmp(lr_eval_string(paramName), lr_eval_string("{report_id}")) == 0) {
	        reportFound = 1;
	        break;
	    }
	}
		
	if (reportFound == 1) {
		lr_output_message("Отчет успешно сохранен");
	    lr_end_transaction("UC_04_TR_05_CheckReport", LR_PASS);
	} else {
		lr_error_message("Отчет не сохранен");
	    lr_end_transaction("UC_04_TR_05_CheckReport", LR_FAIL);
	}

	//lr_end_transaction("UC_04_TR_05_CheckReport",LR_AUTO);

	lr_start_transaction("UC_04_TR_06_Exit");

	// 1. Очищаем все куки
	web_cleanup_cookies();
	
	// 2. Очищаем кэш
	web_cache_cleanup();
	
	// 3. Удаляем все сохраненные параметры
	web_cleanup_auto_headers();
	
	lr_end_transaction("UC_04_TR_06_Exit",LR_AUTO);

	return 0;
}