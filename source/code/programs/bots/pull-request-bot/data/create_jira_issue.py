#!/usr/bin/env python

#explanation:  this is going to create the issue based on the data passed in
#it will then return the issue tag back to the user.  
#the issue tag can then be used to query things about the iseue.
#it is also used to derive the branch name.

#docs:
#jira.readthedocs.io/en/latest/installation.html

#python libraries needed
from jira import JIRA
import ssl
import urllib3
import sys


#CONSTANTS THAT WON"T CHANGE
#UNLESS SOMEONE CHANGES JIRA SETTINGS:

##workflow constants:
BEGIN_WORK_ID = '201'
CODE_COMPLETE_ID = '91'

#Tag names:  
PROJECT_TAG = 'project'
DESCRIPTION_TAG = 'description'
SUMMARY_TAG = 'summary'
ISSUE_TYPE_TAG = 'issuetype'
FIX_VERSIONS_TAG = 'fixVersions'
ASSIGNEE_TAG = 'assignee'
COMPONENTS_TAG = 'components'
VERSION_FOUND_TAG = 'customfield_10700'
REPORT_TYPE_TAG = 'customfield_10412'



#read data in from a C++ program
project_id = sys.argv[1]
issue_type = sys.argv[2]
jira_url = sys.argv[3]
jira_username = sys.argv[4]
jira_password = sys.argv[5]
input_description = sys.argv[6]
input_summary = sys.argv[7]
build_number = sys.argv[8]
report_type = sys.argv[9]
assignee = sys.argv[10]
component = sys.argv[11]

#Final tag values:
PROJECT_VALUE = project_id
DESCRIPTION_VALUE = input_description
SUMMARY_VALUE = input_summary
ISSUE_TYPE_VALUE = {'name': issue_type}
FIX_VERSIONS_VALUE = [{'name': build_number}]
ASSIGNEE_VALUE = {'name': assignee}
COMPONENTS_VALUE = [{'name': component}]
VERSION_FOUND_VALUE = {'name': build_number}
REPORT_TYPE_VALUE = {'value': report_type}

#log in to Jira with username and password
authed_jira = JIRA(jira_url,basic_auth=(jira_username,jira_password))

#Create issue dictionary
issue_dict = {
    PROJECT_TAG: PROJECT_VALUE,
    DESCRIPTION_TAG: DESCRIPTION_VALUE,
    SUMMARY_TAG: SUMMARY_VALUE,
    ISSUE_TYPE_TAG: ISSUE_TYPE_VALUE,
    FIX_VERSIONS_TAG: FIX_VERSIONS_VALUE,
    
    ASSIGNEE_TAG: ASSIGNEE_VALUE,
    COMPONENTS_TAG: COMPONENTS_VALUE,
    VERSION_FOUND_TAG: VERSION_FOUND_VALUE,
    REPORT_TYPE_TAG: REPORT_TYPE_VALUE
}

#create issue
new_issue = authed_jira.create_issue(fields=issue_dict)

#new_issue = authed_jira.issue('UHMEP-1506')
print(new_issue)

#transition through the workflow coding->complete
authed_jira.transition_issue(new_issue, BEGIN_WORK_ID)
authed_jira.transition_issue(new_issue, CODE_COMPLETE_ID)

#git checkout -b "feature/UHMEP-1506-test" "development"
#catch-up-with-dev


