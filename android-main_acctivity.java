package com.example.sasidaran.http;

import android.app.ProgressDialog;
import android.content.Intent;
import android.os.AsyncTask;
import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.util.Log;
import android.view.View;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.AdapterView;
import android.widget.AdapterView.OnItemClickListener;
import android.widget.ListAdapter;
import android.widget.ListView;
import android.widget.SimpleAdapter;
import android.widget.TextView;
import android.widget.Toast;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.util.ArrayList;
import java.util.HashMap;

public class MainActivity extends AppCompatActivity {
    private String TAG = MainActivity.class.getSimpleName();
    private String org_id="organization_id=640012962";
    private String auth_token="authtoken=3f8e56c4e3f26067fa3c86cad4f54634&";
    private static String url = "https://invoice.zoho.com/api/v3/invoices?authtoken=3f8e56c4e3f26067fa3c86cad4f54634&organization_id=640012962";
    private ProgressDialog pDialog;
    ArrayList<HashMap<String, String>> contactList;
    ArrayList<String> invoice_id=new ArrayList<String>();
    private ListView list;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        list = (ListView) findViewById(R.id.list);
        contactList = new ArrayList<>();
        new GetContacts().execute();

    }

    private class GetContacts extends AsyncTask<Void, Void, Void> {
        @Override
        protected void onPreExecute() {
            super.onPreExecute();
            // Showing progress dialog
            pDialog = new ProgressDialog(MainActivity.this);
            pDialog.setMessage("Please wait...");
            pDialog.setCancelable(false);
            pDialog.show();

        }
        @Override
        protected Void doInBackground(Void... arg0) {
            HttpHandler sh = new HttpHandler();

            // Making a request to url and getting response
            String jsonStr = sh.makeServiceCall(url);

            Log.e(TAG, "Response from url: " + jsonStr);
            if (jsonStr != null) {
                try {
                    JSONObject jsonObj = new JSONObject(jsonStr);

                    // Getting JSON Array node
                    JSONArray invoice = jsonObj.getJSONArray("invoices");

                    // looping through All Contacts
                    for (int i = 0; i < invoice.length(); i++) {
                        JSONObject c = invoice.getJSONObject(i);

                        String id = c.getString("invoice_id");
                        String status = c.getString("status");
                        String customer_name = c.getString("customer_name");
                        String due_date = c.getString("due_date");


                        invoice_id.add(id);

                        // tmp hash map for single contact
                        HashMap<String, String> invoices = new HashMap<>();

                        // adding each child node to HashMap key => value
                        invoices.put("id", id);
                        invoices.put("status", status);
                        invoices.put("customer_name", customer_name);
                        invoices.put("due_date", due_date);

                        // adding contact to contact list
                        contactList.add(invoices);
                    }
                } catch (final JSONException e) {
                    Log.e(TAG, "Json parsing error: " + e.getMessage());
                    runOnUiThread(new Runnable() {
                        @Override
                        public void run() {
                            Toast.makeText(getApplicationContext(),
                                    "Json parsing error: " + e.getMessage(),
                                    Toast.LENGTH_LONG)
                                    .show();
                        }
                    });

                }
            } else {
                Log.e(TAG, "Couldn't get json from server.");
                runOnUiThread(new Runnable() {
                    @Override
                    public void run() {
                        Toast.makeText(getApplicationContext(),
                                "Couldn't get json from server. Check LogCat for possible errors!",
                                Toast.LENGTH_LONG)
                                .show();
                    }
                });

            }

            return null;

        }
     @Override
        protected void onPostExecute(Void result)
     {
         super.onPostExecute(result);
         if(pDialog.isShowing())
             pDialog.dismiss();
         ListAdapter adapter=new SimpleAdapter(MainActivity.this,contactList,R.layout.list_item,new String[]{"id","status","customer_name"},new int[]{R.id.name,R.id.email,R.id.mobile});
         list.setAdapter(adapter);
         list.setOnItemClickListener(new OnItemClickListener() {
             @Override
             public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                 Intent intent = new Intent(MainActivity.this, ViewInvoice.class);
                 String txt = invoice_id.get(position);
                 Log.d("invoice_id", txt);
                 intent.putExtra("INVOICE_ID",txt);
                 intent.putExtra("ORG_ID",org_id);
                 intent.putExtra("AUTH",auth_token);
                 startActivity(intent);
             }
         });



     }
    }
}
