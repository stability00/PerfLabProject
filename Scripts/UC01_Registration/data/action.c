Action()
{

	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_url("dev-boomq.pflb.ru", 
		"URL=http://dev-boomq.pflb.ru/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t23.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=https://dev-boomq.pflb.ru/static/media/logo.f5ae2890e77693e018920d4ad41c643c.svg", "Referer=https://dev-boomq.pflb.ru/authorize", ENDITEM, 
		"Url=https://dev-boomq.pflb.ru/static/media/loading.b59fa25397e07d75b9ac55ace151e625.svg", "Referer=https://dev-boomq.pflb.ru/authorize", ENDITEM, 
		"Url=https://dev-boomq.pflb.ru/static/media/Montserrat-Regular.3db65dc4b858f0fed4fb.woff", "Referer=https://dev-boomq.pflb.ru/static/css/main.64a4c65b.css", ENDITEM, 
		"Url=https://dev-boomq.pflb.ru/static/media/Montserrat-Medium.d42dad28f6470e5162c2.woff", "Referer=https://dev-boomq.pflb.ru/static/css/main.64a4c65b.css", ENDITEM, 
		"Url=https://dev-boomq.pflb.ru/static/media/Montserrat-SemiBold.197213592de7a2a62e06.woff", "Referer=https://dev-boomq.pflb.ru/static/css/main.64a4c65b.css", ENDITEM, 
		"Url=https://dev-boomq.pflb.ru/static/media/Montserrat-Bold.180ba33d8de7dcfe80a0.woff", "Referer=https://dev-boomq.pflb.ru/static/css/main.64a4c65b.css", ENDITEM, 
		LAST);

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
		"2026-02-08T15:42:44.118Z");

	web_add_auto_header("sec-ch-ua", 
		"\"Not(A:Brand\";v=\"8\", \"Chromium\";v=\"144\", \"Microsoft Edge\";v=\"144\"");

	web_add_auto_header("sec-ch-ua-mobile", 
		"?0");

	web_add_auto_header("sec-ch-ua-platform", 
		"\"Windows\"");

	lr_think_time(10);

	web_submit_data("login", 
		"Action=https://dev-boomq.pflb.ru/auth-srv/login", 
		"Method=POST", 
		"EncType=multipart/form-data", 
		"TargetFrame=", 
		"Referer=https://dev-boomq.pflb.ru/authorize", 
		"Snapshot=t24.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=username", "Value=admin_gr3@mail.com", ENDITEM, 
		"Name=password", "Value=Wsx321!@#", ENDITEM, 
		"Name=submit", "Value=Login", ENDITEM, 
		LAST);

	web_url("config.json", 
		"URL=https://dev-boomq.pflb.ru/config.json", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t25.inf", 
		"Mode=HTML", 
		LAST);

	web_url("user", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/user", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t26.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=../static/media/en.b1acfc6b06bfe6e29bfbfc06d09d8177.svg", "Referer=https://dev-boomq.pflb.ru/account/new-test", ENDITEM, 
		LAST);

	web_url("modelSchema", 
		"URL=https://dev-boomq.pflb.ru/project-srv/modelSchema", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t27.inf", 
		"Mode=HTML", 
		LAST);

	web_url("identityProvider", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/identityProvider", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t28.inf", 
		"Mode=HTML", 
		LAST);

	web_url("team", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/team?size=2", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t29.inf", 
		"Mode=HTML", 
		LAST);

	web_url("teamContext", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/teamMember/teamContext?teamId=22", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t30.inf", 
		"Mode=HTML", 
		LAST);

	web_url("testRunner", 
		"URL=https://dev-boomq.pflb.ru/test-runner-srv/testRunner?sort=id,desc", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t31.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("login",LR_AUTO);

	lr_think_time(13);

	lr_start_transaction("edit_team");

	web_url("team_2", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/team?page=0&size=7", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/teams", 
		"Snapshot=t32.inf", 
		"Mode=HTML", 
		LAST);

	web_url("22", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/team/22", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/teams/22", 
		"Snapshot=t33.inf", 
		"Mode=HTML", 
		LAST);

	web_url("teamMember", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/teamMember?teamId=22&page=0&size=7", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/teams/22", 
		"Snapshot=t34.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("edit_team",LR_AUTO);

	lr_start_transaction("add_user");

	web_add_header("Origin", 
		"https://dev-boomq.pflb.ru");

	lr_think_time(22);

	web_custom_request("teamMember_2", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/teamMember?teamId=22", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/teams/22", 
		"Snapshot=t35.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body=[{\"email\":\"test123@qwe.com\",\"permissionList\":[\"VIEW\",\"EDIT\",\"RUN\"],\"userDisplayName\":\"test123\"}]", 
		LAST);

	web_url("teamMember_3", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/teamMember?teamId=22&page=0&size=7", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/teams/22", 
		"Snapshot=t36.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("add_user",LR_AUTO);

	lr_start_transaction("save_user");

	web_add_header("Origin", 
		"https://dev-boomq.pflb.ru");

	lr_think_time(25);

	web_custom_request("teamMember_4", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/teamMember?teamId=22", 
		"Method=PUT", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/teams/22", 
		"Snapshot=t37.inf", 
		"Mode=HTML", 
		"Body=[{\"email\":\"test123@qwe.com\",\"id\":4235,\"permissionList\":[\"VIEW\",\"EDIT\",\"RUN\"],\"teamId\":\"22\",\"userDisplayName\":\"test123\",\"userId\":3946,\"updateInviteExpiration\":true}]", 
		LAST);

	web_add_auto_header("Sec-Fetch-Site", 
		"none");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Dest", 
		"document");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_url("eyc9ZpKsMB1L9hvaNSaIQWDxwqYxYFu_u-u_abHVE1OZJ-WigbFZohTCepyeBWPTmuQwJ43jLGwtybRPbARdGrezXRjEAqPUNcJx454Xeo4=", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/invite/eyc9ZpKsMB1L9hvaNSaIQWDxwqYxYFu_u-u_abHVE1OZJ-WigbFZohTCepyeBWPTmuQwJ43jLGwtybRPbARdGrezXRjEAqPUNcJx454Xeo4=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t38.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("Origin", 
		"https://dev-boomq.pflb.ru");

	web_add_auto_header("Sec-Fetch-Dest", 
		"empty");

	web_add_auto_header("Sec-Fetch-Mode", 
		"cors");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	lr_think_time(5);

	web_custom_request("user_2", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/user", 
		"Method=PUT", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/change-password", 
		"Snapshot=t39.inf", 
		"Mode=HTML", 
		"Body={\"password\":\"Wsx321!@#\\t\"}", 
		LAST);

	web_url("team_3", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/team?size=2", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t40.inf", 
		"Mode=HTML", 
		LAST);

	web_url("teamContext_2", 
		"URL=https://dev-boomq.pflb.ru/auth-srv/teamMember/teamContext?teamId=22", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t41.inf", 
		"Mode=HTML", 
		LAST);

	web_url("testRunner_2", 
		"URL=https://dev-boomq.pflb.ru/test-runner-srv/testRunner?sort=id,desc", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://dev-boomq.pflb.ru/account/new-test", 
		"Snapshot=t42.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("save_user",LR_AUTO);

	return 0;
}