package com.example.sasidaran.http;

import android.app.ProgressDialog;
import android.content.Intent;
import android.os.AsyncTask;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.widget.TextView;

import java.lang.StringBuilder;
/**
 * Created by Sasidaran on 15-01-2017.
 */
public class ViewInvoice extends AppCompatActivity {
    private StringBuilder url = new StringBuilder("https://invoice.zoho.com/api/v3/invoices");
    private ProgressDialog pDialog;
    private TextView txt;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        Bundle extras = getIntent().getExtras();
        String org_id = null;
        String auth = null;
        String invoice_id = null;
        if (extras != null) {
            org_id = extras.getString("ORG_ID");
            auth = extras.getString("AUTH");
            invoice_id = extras.getString("INVOICE_ID");

        }
        updateURL(org_id, auth, invoice_id);
        setContentView(R.layout.invoice_display);

    }

    public void updateURL(String org, String auth, String invoice_id) {
        url.append("/");
        url.append(invoice_id);
        url.append("?");
        url.append(auth);
        url.append(org);
        Log.d("URL", url.toString());
        HttpHandler sh = new HttpHandler();

        // Making a request to url and getting response
        String jsonStr = sh.makeServiceCall(url.toString());
        Log.d("invoice", "hii");
    }

}
